//some thing wrong in queue implemntaion by using array

#include<stdio.h>
#include<stdbool.h>

int fx[] = {-1,+1, 0, 0 ,-1, +1, -1, +1};
int fy[] = {0 , 0,+1,-1, -1, +1, +1, -1};
int m, n;

char greed[100][100];
int visited[100][100];

struct Point{
    int x,y;
};
void inti(){
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
}

bool valid(int x, int y){
    if(x < 0 || y < 0)
        return false;
    if(x >= m || y >= n)
        return false;
    return true;
}

void BFS(int x, int y){
    struct Point queue[10000], newPoint, point;
    newPoint.x = x, newPoint.y = y;
    int qPos = 0;
    queue[qPos++] = newPoint;
    visited[newPoint.x][newPoint.y] = 1;

    while(qPos>0){
        int i;
        qPos--;
        point = queue[qPos];
        for(i = 0; i < 8; i++){
            newPoint = point;
            newPoint.x += fx[i];
            newPoint.y += fy[i];
            if(valid(newPoint.x,newPoint.y) && !(visited[newPoint.x][newPoint.y]) && greed[newPoint.x][newPoint.y] == '@'){
                visited[newPoint.x][newPoint.y] = 1;
                queue[qPos] = newPoint;
                qPos++;
            }
        }
    }
}

int main(){
    int i, j;
    while(scanf("%d %d",&m, &n) && m){
        for(i = 0; i <m; i++)
            scanf("%s",&greed[i]);
        inti();
        int count = 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(greed[i][j] == '@' && !(visited[i][j])){
                    count++;
                    BFS(i,j);
                }
            }
        }
        printf("%d\n",count);
    }

    return 0;
}
