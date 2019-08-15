#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char grid[105][105];
int visited[105][105];
int fx[] = {-1,+1, 0, 0 ,-1, +1, -1, +1};
int fy[] = {0 , 0,+1,-1, -1, +1, +1, -1};
int ans;
void DFS(int a, int b){
   // printf("coordinate : %d , %d\n",a,b);
    if(a < 0 || b < 0 || grid[a][b] == 0)
        return ;
    if(visited[a][b] == -1 || grid[a][b] != 'W')
        return ;
    if(visited[a][b] && grid[a][b] == 'W'){
        ans = visited[a][b];
        return;
    }
    visited[a][b] = -1;
    ans++;
    int i;
    for(i = 0; i < 8; i++){
        DFS(a+fx[i],b+fy[i]);
    }
    cout << "Answer " << ans << endl;
    visited[a][b] = ans;
    //printf("Qord");
}

int main(){
    int t, n, a, b;
    char str[105];
    scanf("%d",&t);
    getchar();
    while(t--){
        n = 0;
        memset(grid,0,sizeof(grid));
        memset(visited,0,sizeof(visited));
        getchar();
        while(scanf("%[^\n]",str)){
            getchar();
            if(str[0]=='\0') break;
            if(str[0] == 'W' || str[0] == 'L'){
                sscanf(str,"%s",grid[n]);
                n++;
            }
            else{
                ans = 0;
                sscanf(str,"%d %d",&a,&b);
                DFS(a-1,b-1);
                printf("%d\n",ans);
            }
        }
        if(t) printf("\n");
    }

    return 0;
}