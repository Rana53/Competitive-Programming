#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, wi;
    string line;
    cin >> n;

    int ara[n];
    map<int,int> mp;
    map<int,int> ::iterator it;
    for(int i = 0; i < n; i++){
        cin >> wi;
        mp[wi] = i+1;
    }
    cin >> line;
    it = mp.begin();
    priority_queue<int> myqueue;
    for(int i = 0; i < n * 2; i++){
        if(line[i] == '0'){
            cout << it->second;
            myqueue.push(it->first);
            it++;
        }
        else {
            int val = myqueue.top();
            cout << mp[val];
            myqueue.pop();
        }

        if(i+1 != n*2)
            cout << " ";
    }
    cout <<endl;
    return 0;
}