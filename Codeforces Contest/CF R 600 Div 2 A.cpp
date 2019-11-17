#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int araA[n], araB[n], dif, firstDif = 0, difPos = n;
        bool possible = true;
        for(int i = 0; i < n; i++)
            cin >> araA[i];
        for(int i = 0; i < n; i++)
            cin >> araB[i];
        for(int i = 0; i < n; i++){
            dif = araB[i] -araA[i];
            if(dif < 0){
                possible = false;
                difPos = n;
                break;
            }
            else if(dif > 0) {
                firstDif = dif;
                difPos = i;
                break;
            }
        }
        int j;
        for(j = difPos + 1; j < n; j++){
            dif = araB[j] - araA[j];
            if(dif < 0){
                possible = false;
                difPos = n;
                break;
            }
            else if( dif != firstDif){
                break;
            }
        }
        for( j; j < n; j++){
            dif = araB[j] - araA[j];
            if(dif != 0){
                possible = false;
                difPos = n;
                break;
            }
        }
        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}