#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    map< string, int> Hash;
    string line;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> line;
        if(!Hash[line])
            cout << "OK" << endl;
        else
            cout << line << Hash[line] << endl;
        Hash[line]++;
    }

    return 0;
}
