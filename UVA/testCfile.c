
#include<stdio.h>
#include<string.h>
char grid[105][105];
int visited[105][105];
int fx[] = {-1,+1, 0, 0 ,-1, +1, -1, +1};
int fy[] = {0 , 0,+1,-1, -1, +1, +1, -1};
int ans;
void DFS(int a, int b){
   // printf("coordinate : %d , %d\n",a,b);
    if(a < 0 || b < 0 || grid[a][b] == 0)
        return ;
    if(visited[a][b] != 0 || grid[a][b] != 'W')
        return ;
    visited[a][b] = 1;
    ans++;
    int i;
    for(i = 0; i < 8; i++)
        DFS(a+fx[i],b+fy[i]);
}

int main(){
    int t, n, a, b;
    char str[105];
    scanf("%d ",&t);
    //getchar();
    while(t--){
        printf("t is - %d",t);
        n = 0;
        memset(grid,0,sizeof(grid));
        //getchar();
        while(gets(str)){
            printf("string - %s\n", str);
           // getchar();
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

/*
#include <stdio.h>
#include <string.h>

char map[105][105], used[105][105];
int ans;
void dfs(int x, int y) {
    if(x < 0 || y < 0 || map[x][y] == 0)
        return;
    if(used[x][y] != 0 || map[x][y] != 'W')
        return;
    used[x][y] = 1;
    ans++;
    int i, j;
    for(i = -1; i <= 1; i++)
        for(j = -1; j <= 1; j++)
            dfs(x+i, y+j);
}
int main() {
    int t, i, j;
    char str[105];
    scanf("%d ", &t);
    while(t--) {
        memset(map, 0, sizeof(map));
        int n = 0;
        while(gets(str)) {
            if(str[0] == '\0')
                break;
            if(str[0] != 'W' && str[0] != 'L') {
                sscanf(str, "%d %d", &i, &j);
                memset(used, 0, sizeof(used));
                ans = 0;
                dfs(i-1, j-1);
                printf("%d\n", ans);
            } else {
                sscanf(str, "%s", map[n]);
                n++;
            }
        }
        if(t)
            puts("");
    }
    return 0;
}
*/
