#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int Graph[11][11];
bool visited[11];
int level[11];

void BFS(void){
    int queue[11], qPos = 0, qLimit, u, v;
    queue[qPos] = 0;
    visited[0] = 1;
    level[0] = 0;
    qLimit = 1;
    while(qPos < qLimit){
        u = queue[qPos];
        qPos++;
        //printf("queue");
        for(v = 0; v < 11; v++){
            if(Graph[u][v] && !(visited[v])){
                queue[qLimit++] = v;
               // printf("queue");
                level[v] = level[u] + 1;
                visited[v] = 1;
            }
        }
    }
}

int main(){
    int n, e, i, u ,v;
    printf("Number of node and edge: ");
    scanf("%d %d",&n,&e);
    memset(level,0,sizeof(level));
    memset(visited,0,sizeof(visited));
    for( i = 0; i < e; i++){
        scanf("%d %d",&u ,&v);
        Graph[u][v] = 1;
    }
    BFS();
    for( i = 0; i < 11; i++){
        printf("Node %d ---> level %d\n", i, level[i]);
    }
    return 0;
}

/*
11 13
0 1
0 2
0 3
1 4
1 5
2 6
2 7
3 7
4 8
5 8
6 9
7 10
9 10

*/
