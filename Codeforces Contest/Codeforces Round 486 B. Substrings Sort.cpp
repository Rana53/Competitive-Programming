#include<bits/stdc++.h>
using namespace std;
vector<string>v;

bool acompare(const string& a, const string& b)
{
    return (a.size() < b.size());
}

bool isSubString(int i , int n){
    int j = i;
    for(i++ ; i < n; i++){
        if(v[i].find(v[j]) != string::npos){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(),v.end(),acompare);
    bool subStr = true;

    for(int i = 0; i < n - 1; i++){
        if(!isSubString(i,n)){
            subStr = false;
            break;
        }
    }
    if(subStr){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
        cout << v[i] << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
