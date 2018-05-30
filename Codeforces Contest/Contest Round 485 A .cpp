#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string line;
    map<string,string> mp;
    map<string,string> ::iterator it;
    mp["purple"] = "Power";
    mp["green"] = "Time";
    mp["blue"] = "Space";
    mp["orange"] = "Soul";
    mp["red"] = "Reality";
    mp["yellow"] = "Mind";

    cin >> n;
    for(int i =0; i < n; i++){
        cin >> line;
        mp.erase(line);
    }
    cout << mp.size() << endl;
    for(it = mp.begin(); it!=mp.end(); it++)
        cout << it->second << endl;

    return 0;
}
