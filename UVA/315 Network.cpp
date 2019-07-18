#include<iostream>
#include<cstdio>
#include<cstring>

#define MAX 101
using namespace std;
int graph[MAX][MAX];
int visited[MAX];
int count;
int sz[MAX];

void init(int n){
    for(int i = 1; i <= n; i++){
        sz [i]= 0;
        visited[i] = 0;
    }
}

void DFS(int u){
    visited[u] = 1;
    count++;
    int s = sz[u];
    for(int i = 0;i < s; i++)
        if(!visited[graph[u][i]])
            DFS(graph[u][i]);
    return;
}

int main(){
    int n, u, v, criticalNode;
    while(cin>>n && n){
        criticalNode = 0;
        init(n);
        while(cin>>u && u){
            while(cin>>v){
                graph[u][sz[u]++] = v;
                graph[v][sz[v]++] = u;
                if(cin.get()=='\n') break;
            }
        }
        for(int i = 1; i <= n; i++){
            memset(visited,0,sizeof(visited));
            visited[i] = 1;
            count = 0;
            if(i != 1)
                DFS(1);
            else
                DFS(2);
           // cout << i << " : count is : " << count << endl;
            if(count+1 != n)
                criticalNode++;
        }
        cout << criticalNode << endl;
    }
    return 0;
}

/*
input :

5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
9
3 1 2
5 3 4 6 2
7 1 9 8
0
12
1 7 10
2 1 3 4
3 5 11 12
4 5 6
8 9 7
0
output:
1
2
4
6
*/
