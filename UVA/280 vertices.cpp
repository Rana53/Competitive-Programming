#include<iostream>
#include<cstring>

int graph[101][101];
int sz[101];
int visited[101];

using namespace std;
int DFS(int root){
    int count = 0;
    int stack[101], siz = 0, u, v;
    stack[siz++] = root;
    while(siz>0){
        u = stack[--siz];
        for(int i = 0; i < sz[u]; i++){
            v = graph[u][i];
            cout << "Visited " << v << endl;
            if(!visited[v]){
                //cout << "Visited " << v << endl;
                stack[siz++] = v;
                count++;
                visited[v] = 1;
            }
        }
    }
    return count;
}

void printGraph(){
    for(int i = 0; i < 10; i++){
        cout << i << ":" << sz[i] << ":";
        for(int j = 0; j < sz[i];j++)
            cout <<" " << graph[i][j];
        cout << endl;
    }
}

int main(){
    int u, v, n, lineN, root, in;
    while(cin >> n, n){
        memset(sz,0,sizeof(sz));
        memset(graph,0,sizeof(graph));
        while(cin>>u,u){
            while(cin>>v,v){
                graph[u][sz[u]++] = v;
            }
        }
        cin >> lineN;
        while(lineN--){
            memset(visited,0,sizeof(visited));
            cin >> root;
            cout << root << endl;
            int count = DFS(root);
            cout << n - count << endl;
        }
    }

    return 0;
}


/*
3
1 2 0
2 2 0
3 1 2 0
0
2 1 2

8
1 2 0
1 3 0
2 5 0
5 6 0
6 3 0
3 1 0
3 1 4 7 8 0
0

*/
