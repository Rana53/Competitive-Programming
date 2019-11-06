#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string sStr, tStr;
        int n;
        cin >> n;
        cin >> sStr;
        cin >> tStr;
        int dif = 0, diffPos[2];
        for(int i = 0; i < n; i++){
            if(sStr[i] != tStr[i]){
               dif++;
               if(dif < 3)
                   diffPos[dif-1] = i;
            }
        }
        if(dif == 2){
            if((tStr[diffPos[0]] == tStr[diffPos[1]]) && (sStr[diffPos[0]] == sStr[diffPos[1]]))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}
