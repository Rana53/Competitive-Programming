#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, a ,x;
    cin >> n;
    map<int,int> mp;
    map<int,int> ::iterator it;
    for(int i = 0; i < n; i++){
        cin >> a >> x;
        mp[a] = x;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> x;
        if(mp[a] < x)
            mp[a] = x;
    }
    long long result = 0;
    for(it = mp.begin(); it!=mp.end();it++){
        result += it->second;
    }
    cout << result << endl;
    return 0;
}
