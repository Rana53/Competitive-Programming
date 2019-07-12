#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int Graph[100001][100001];
bool visited[100001];
int level[100001];
int l;
int count = 0;

void BFS(void){
    int queue[11], qPos = 0, qLimit, u, v;
    queue[qPos] = 1;
    visited[1] = 1;
    level[1] = 0;
    qLimit = 1;
    while(qPos < qLimit){
        u = queue[qPos];
        qPos++;
        //printf("queue");
        for(v = 0; v < 100001; v++){
            if(Graph[u][v] && !(visited[v])){
                queue[qLimit++] = v;
                level[v] = level[u] + 1;
                visited[v] = 1;
                if(level[v] == l)
                    count++;
            }
        }
    }
}

int main(){
    int n, i, u, v;
    scanf("%d",&n);
    memset(level,0,sizeof(level));
    memset(visited,0,sizeof(visited));
    for( i = 1; i < n; i++){
        scanf("%d %d",&u ,&v);
        Graph[u][v] = 1;
    }
    scanf("%d",&l);
    BFS();
    printf("%d\n",count);

    return 0;
}
