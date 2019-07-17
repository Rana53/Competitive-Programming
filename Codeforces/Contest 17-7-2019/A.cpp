#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, num;
    cin >> n >> k;
    int ara[k+1];
    memset(ara,0,sizeof(ara));
    for(int i = 0; i < n; i++){
        cin >> num;
        ara[num]++;
    }
    sort(ara,ara+k+1);
    int takeSet, count;
    takeSet = (n/2) + (n%2);
    count = 0;
    for(int i = k; takeSet > 0; i--){
        if(ara[i] <= (takeSet*2)){
            count += ara[i];
            takeSet -= ((ara[i]/2)+(ara[i]%2));
        }
        else{
            count += takeSet * 2;
            takeSet = 0;
        }

    }
    cout << count << endl;
    return 0;
}
