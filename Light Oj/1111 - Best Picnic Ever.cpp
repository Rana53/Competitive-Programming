#include<bits/stdc++.h>
 
using namespace std;
vector<int>V[1009];
int _count[1009], n, visit[1009], m, k, ans , ara[100];
 
void bfs(int s){
    for(int i=0;i<=n;i++) visit[i]=0;
    visit[s]=1;
    queue<int>q;
    q.push(s);
    _count[s]++;
    if(_count[s]==k) ans++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int j=0; j<V[u].size(); j++){
            int v=V[u][j];
            if(!visit[v]){
                q.push(v);
                visit[v]=1;
                _count[v]++;
                if(_count[v]==k) ans++;
            }
        }
    }
}
 
int main(){
    int t, tcs=1, u, v;
    cin>>t;
    while(t--){
        ans=0;
        cin>>k>>n>>m;
        for(int i=0;i<k;i++) cin>>ara[i];
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            V[u].push_back(v);
        }
        for(int i=0;i<=n;i++) _count[i]=0;
        for(int x=0; x<k; x++){
            bfs(ara[x]);
        }
        cout<<"Case "<<tcs++<<": "<<ans<<endl;
        for(int i=0;i<=n;i++) V[i].clear();
    }
    return 0;
}
 