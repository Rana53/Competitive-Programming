#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
struct Point{
    int x, y;
};
int sz;

char grid[25][25];
int visited[25][25];

int fx[] = {-1,+1, 0, 0 ,-1, +1, -1, +1};
int fy[] = {0 , 0,+1,-1, -1, +1, +1, -1};

void inti(int n){
    int ii, jj;
    for( ii = 0; ii < n; ii++){
        for( jj = 0; jj < n; jj++){
            visited[ii][jj] = 0;
        }
        grid[ii][0] = '\0';
    }
}

bool valid(struct Point point){

    if(point.x < 0 || point.y < 0)
        return false;
    if(point.x >= sz || point.y >= sz)
        return false;
    return true;
}
void BFS(int x , int y){
    struct Point point, newPoint, queue[1000];
    point.x  = x;
    point.y = y;
    int qPos = 0, qLimit, k;
    queue[qPos]= point;
    qLimit = 1;
    visited[point.x][point.y] = 1;
    while(qPos < qLimit){
        point = queue[qPos++];
        for( k = 0; k < 8; k++){
            newPoint.x = point.x + fx[k];
            newPoint.y = point.y + fy[k];
            if(valid(newPoint) && !(visited[newPoint.x][newPoint.y])&& grid[newPoint.x][newPoint.y] == '1'){
                queue[qLimit++] = newPoint;
                visited[newPoint.x][newPoint.y] = 1;
            }
        }
    }
}

int main(){
    FILE *fileIn, *fileOut;
    fileIn = fopen("352in.txt","r");
    fileOut = fopen("352out.txt","w");

    int n, i, j, number = 0;
    while(fscanf(fileIn,"%d",&n) !=EOF){
        inti(n);
        number++;
        for( i = 0; i < n; i++){
            fscanf(fileIn,"%s",grid[i]);
        }
        sz = n;
        int count = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(grid[i][j]=='1' && !(visited[i][j])){
                    count++;
                    BFS(i, j);
                }
            }

        }
        fprintf(fileOut,"%s","Image number ");
        fprintf(fileOut,"%d",number);
        fprintf(fileOut,"%s"," contains ");
        fprintf(fileOut,"%d",count);
        fprintf(fileOut,"%s"," war eagles.");
        fprintf(fileOut,"\n");
    }

    fclose(fileOut);
    fclose(fileIn);

    return 0;
}

