#include<bits/stdc++.h>
#define M 1000003
#define LL long long
using namespace std;
vector < LL > factorial;
void factorialConstruct(LL n){
    factorial.resize(n);
    factorial[0] = 1;
    for(LL i = 1; i < n; i++){
        factorial[i] = (i*factorial[i-1])%M;
    }
}
LL modularInverse(LL a,LL p){
    if(p == 1)
        return a;
    if(p%2==1) return modularInverse(a,p-1)*a%M;
    else{
        long long res = modularInverse(a,p/2);
        return (res%M)*(res%M)%M;
    }
}
int main(){
    int t, tc= 1;
    factorialConstruct(1000005);

    cin >> t;
    while(t--){
        LL n, r , result;
        cin >> n >> r;
        result = ((factorial[n-r]%M) * (factorial[r]%M)) % M;
        result = modularInverse(result,M-2);
        result = ((result%M) * (factorial[n] %M)) % M;
        printf("Case %d: %lld\n",tc,result);
        tc++;
    }
    return 0;
}
