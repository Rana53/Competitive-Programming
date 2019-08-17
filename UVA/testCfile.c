#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char grid[105][105];
int visited[105][105];
int fx[] = {-1,+1, 0, 0 ,-1, +1, -1, +1};
int fy[] = {0 , 0,+1,-1, -1, +1, +1, -1};
int ans;
void DFS(int a, int b){
    int i;
    if(a < 0 || b < 0 || grid[a][b] == 0)
        return ;
    if(visited[a][b] != 0 || grid[a][b] != 'W')
        return ;
    visited[a][b] = 1;
    ans++;
    for(i = 0; i < 8; i++)
        DFS(a+fx[i],b+fy[i]);
}

int main(){
    int t, n, a, b;
    char str[105];
    scanf("%d ",&t);
    while(t--){
        n = 0;
        memset(grid,0,sizeof(grid));
        while(gets(str)){
            if(str[0]=='\0') break;
            if(str[0] == 'W' || str[0] == 'L'){
                sscanf(str,"%s",grid[n]);
                n++;
            }
            else{
                ans = 0;
                memset(visited,0,sizeof(visited));
                sscanf(str,"%d %d",&a,&b);
                DFS(a-1,b-1);
                printf("%d\n",ans);
            }
        }
        if(t) printf("\n");
    }
    return 0;
}
