#include<bits/stdc++.h>
using namespace std;
int main(){
    int l, r, a, dif, total;
    cin >> l >> r >> a;
    total = l + r;
    dif = abs(l-r);

    if(a>=dif){
        total += dif;
        total += ((a - dif) / 2);
    }
    else{
        total += a * 2;
        total -= dif;
    }
    if( (!l && !a) || (!r && !a))
        cout << 0 << endl;

    cout << total << endl;

    return 0;
}
