#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> > Graph;

int graphTravels(int root, int dis, map<int,int> visited){
    int visitCount = 1;
    queue<int> Q;
    Q.push(root);
    visited[root] = 1;
    while(!Q.empty()){
        int u, sz;
        u = Q.front();
        Q.pop();
        sz = Graph[u].size();
        for(int i = 0; i < sz ; i++){
            int v = Graph[u][i];
            if(visited[v] == 0){
                cout << v << endl;
                visited[v] = visited[u] + 1;
                Q.push(v);
                visitCount++;
            }
            if(visited[v]>(dis+1)){
                visitCount--;
                return visitCount;
            }
        }
    }
    return visitCount;
}

int main(){
    map<int,int> visited;
    int node, a, b, root, dis, cs = 1;
    while(cin>>node,node){
        for(int i = 0; i < node ;i++){
            cin >> a >> b;
            Graph[a].push_back(b);
            Graph[b].push_back(a);
            visited[a] = 0;
            visited[b] = 0;
        }

        while(cin >> root >> dis, root, dis){
            int sz = Graph.size();
            int visit = graphTravels(root,dis,visited);
            cout << visit << endl;
            //printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs,sz-visit,root,dis);
            cs++;
        }
    }

    return 0;
}
