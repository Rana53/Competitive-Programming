#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char grid[105][105];
int visited[105][105];
int n, count = 0;
int fx[] = {-1,+1,0,0};
int fy[] = {0,0,-1,+1};
int DFS(int i,int j){
    int k;
    if(i<0 || i >= n) return 0;
    if(j<0 || j >= n) return 0;
    if(visited[i][j] != 0 || grid[i][j] !='0') return 0;
    visited[i][j] = 1;
    count++;
    for(k = 0; k < 4; k++)
        DFS(i+fx[k],j+fy[k]);
}

int main(){
    int t, a, b, i;
    char str[105];
    scanf("%d ",&t);
    while(t--){
        gets(str);
        sscanf(str,"%d %d",&a,&b);
        gets(grid[0]);
        n = strlen(grid[0]);
        for(i = 1; i < n; i++){
            gets(grid[i]);
        }
        count = 0;
        DFS(a-1,b-1);
        printf("%d\n",count);
        if(t) puts("");
    }

    return 0;
}
/*
1

02 01
1001101
0011111
0001001
1100011
1111111
1100110
1110111
*/
/*
1 2
10001
10011
11110
10010
10010
*/
