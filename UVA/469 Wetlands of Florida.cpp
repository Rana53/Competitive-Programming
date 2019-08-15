#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
char grid[105][105];
int a , b;
int fx[] = {-1,+1, 0, 0 ,-1, +1, -1, +1};
int fy[] = {0 , 0,+1,-1, -1, +1, +1, -1};
int szN, szM;

struct Point{
   int r, c;
};

bool valid(Point point){
    if(point.r < 0 || point.c < 0)
        return false;
    if(grid[point.r][point.c] != 'W')
        return false;
    return true;
}

int BFS(Point point){
    int visited[105][105];
    memset(visited,0,sizeof(visited));
    Point Q[10000], newPoint, qPoint;
    int qPos, qLimit, count = 1;
    qPos = 0, qLimit = 1;
    Q[qPos] = point;
    visited[point.r][point.c] = 1;
    while(qPos < qLimit){
        qPoint = Q[qPos++];
        for(int i = 0; i < 8; i++){
           newPoint.r = qPoint.r + fx[i];
           newPoint.c = qPoint.c + fy[i];
           if(valid(newPoint) && !(visited[newPoint.r][newPoint.c])){
               Q[qLimit++] = newPoint;
               visited[newPoint.r][newPoint.c] = 1;
               count++;
           }
        }
    }
    return count;
}

int main(){

    bool once;
    int t, n, ans;
    Point point;
    scanf("%d",&t);
    getchar();
    while(t--){
        memset(grid,0,sizeof(grid));
        cin.get();
        szN = 0;
        once = true;
        while(scanf("%[^\n]",grid[szN])){
            getchar();
            if(grid[szN][0] == '\0') break;
            if(grid[szN][0] == 'W' || grid[szN][0] == 'L') szN++;
            else{
                sscanf(grid[szN],"%d %d",&a,&b);
                point.r = a - 1;
                point.c = b - 1;
                ans = BFS(point);
                printf("%d\n",ans);
            }
        }
        if(t) printf("\n");
    }
    return 0;
}
