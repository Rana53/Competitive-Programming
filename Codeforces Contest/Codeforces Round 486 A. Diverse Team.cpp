#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, num;
    map<int,int> mp;
    map<int,int> :: iterator it;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> num;
        mp[num] = i + 1;
    }

    if(mp.size() < k )
        cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        int sz = mp.size();
        int ara[sz];
        it = mp.begin();
        for(int i = 0; i < sz; i++){
            ara[i] = it->second;
            it++;
        }
        sort(ara,ara+sz);
        cout << ara[0];
        for(int i = 1; i < k ;i++)
            cout << " " << ara[i];

        cout << endl;
    }
    return 0;
}
