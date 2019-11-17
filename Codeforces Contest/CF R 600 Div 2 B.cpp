#include<bits/stdc++.h>
#define MX 10000000+7
int day[1000000];
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << MX << endl;
    bool possible = true, end = false;
    int v, count = 0, d = -1;
    map<int,int> myMp;
    for (int i = 0; i < n; i++) {
        cin >> v;
        if (!possible) continue;
        if (v > 0) {
            if (!count){
                 d++;
                 end = false;
                myMp.clear();
            }
            if (!myMp[v]){
                possible = false;
            } else {
                myMp[v] = v;
                day[d]++;
                count++;
            }
        } else {
            if (myMp[-1*v] == v) {
                myMp[-1*v] = 0;
                count--;
                day[d]++;
                if (!count) end = true;
            } else {
                possible = false;
            }
        }
        
    }
    if (!possible) cout << -1 << endl;
    else {
        cout << d + 1 << endl;
        cout << day[0] << endl;
        for (int i = 1; i <= d; i++) {
            cout << " " <<  day[i];
        }
    }
    return 0;
}
 