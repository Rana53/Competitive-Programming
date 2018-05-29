#include<bits/stdc++.h>
using namespace std;
int main(){
    int k, n, s, p, ns, total, res;
    cin >> k >> n >> s >> p;
    ns = (n/s) + ((n%s==0)?0:1);
    total = k * ns;
    res = (total/p) + ((total%p==0)?0:1);
    cout << res<< endl;

    return 0;
}
