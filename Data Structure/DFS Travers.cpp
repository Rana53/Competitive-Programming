#include<bits/stdc++.h>
using namespace std;
bool visited[5];
vector<int> adj[6];
void dfs(int i){
    cout << i << endl;
    visited[i] = true;
    for(int j = 0; j < adj[i].size(); j++)
        if(!visited[adj[i][j]])
        dfs(adj[i][j]);

}
int main(){
    int edge, u, v;
    cin >> edge;
    for(int i = 0; i < edge; i++){
        cin >> u >> v; 01767332686
        adj[u].push_back(v);
    }
    dfs(1);
    return 0;
}
