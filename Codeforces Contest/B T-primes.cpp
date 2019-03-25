#include<bits/stdc++.h>
using namespace std;
int prime[1000002];
bool primeMark[1000006];
int nPrime;
void seive(int n){
    nPrime = 0;
    int limit = sqrt( n * 1.0) + 2;
    primeMark[1] = 1;
    //prime[nPrime++] = 2;
    for(int i = 4; i < n; i +=2)    primeMark[i] = 1;
    for(int i = 3; i <= n; i += 2){
        if(!primeMark[i]){
            //prime[nPrime++] = i;
            if(i <= limit){
                for(int j = i * i; j <= n; j += i * 2){
                    primeMark[j] = 1;
                }
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    seive(1000002);
    int ara[n];
    for(int i = 0; i < n; i ++){
        cin >> ara[i];
    }
    for(int i = 0; i < n; i ++){
      int var = sqrt(ara[i] * 1.0);
      if((!primeMark[var]) && (var * var == ara[i])) cout << "YES" << endl;
      else cout << "NO" << endl;
    }


    return 0;
}
