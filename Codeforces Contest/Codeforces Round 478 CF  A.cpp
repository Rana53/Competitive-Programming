#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string line;
    bool check = true;
    cin >> n;
    cin >> line;
    if(n==1 && line[0] == '0'){
        cout <<"No"<<endl;
        return 0;
    }
    for(int i = 0; i < n-1; i++){
        if(line[0] == '0' && line[1] == '0') check = false;
        if(line[i] == '1' && line[i+1]=='1'){
            check = false;
            break;
        }
    }
    for(int i = 0; i < n-2; i++){
        if(line[i] == '0' && line[i+1]=='0' && line[i+2]=='0'){
            check = false;
            break;
        }
    }

    if(n>=3){
        if(line[n-2]=='0' && line[n-1] == '0') check = false;

    }

    if(check) cout <<  "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
