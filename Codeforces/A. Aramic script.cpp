#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string line[n];
    map<int,int>disValue;
    for(int i = 0; i < n; i++)
        cin >> line[i];
    for(int i = 0; i < n; i++){
        vector<int> v(26,0);
        int len = line[i].size();
        for(int j = 0; j < len; j++){
            v[line[i][j]-'a'] = 1;
        }
        int result = 0;
        for(int j = 0; j < 26; j++)
            if(v[j])
               result += j+1;
        disValue[result];
    }
    cout << disValue.size() << endl;

    return 0;
}
