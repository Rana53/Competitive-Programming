#include<iostream>
#include<cstdio>
#include<cstring>
#define MX 26
using namespace std;
int graph[MX][MX];
int sz[MX];
int visited[MX];

void DFS(int n){
    visited[n] = 1;
    for(int i = 0; i < sz[n];i++)
        if(!visited[graph[n][i]])
            DFS(graph[n][i]);
    return;
}

int main(){
    int n;
    char start, input[2], ch, u, v;
    cin >> n;
    while(n--){
        memset(graph,0,sizeof(graph));
        memset(sz,0,sizeof(sz));
        memset(visited,0,sizeof(visited));

        cin >> start;
        cin.get();
        //cout << "First character inputed" << endl;
        //cout << "start inpu - " << start << endl;
        while(scanf("%[^\n]",input)){
            cin.get();
            //cout << " input graph";
            if(input[0] == '\n') break;
            u = input[0]-'A';
            v = input[1]-'A';
            graph[u][sz[u]++] = v;
            graph[v][sz[v]++] = u;
        }
       // cout << "Graph input end" << endl;
        u = start - 'A';
        if(!sz[u]){
            graph[u][sz[u]++] = u;
        }
        int count = 0;
        for(int i = 0; i < MX; i++){
            if(!visited[i] && sz[i]){
                count++;
                DFS(i);
            }
        }
        cout << count << endl;
        if(n) cout << endl;
    }
    return 0;
}

/*
1


E
AB
CE
DB
EC
*/
