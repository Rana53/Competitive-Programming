
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ara[n];
        for(int i = 0; i < n; i++){
            cin >> ara[i];
        }
        sort(ara,ara+n);
        int count = 0;
        int j = n - 1;
        while(count < ara[j]){
            count++;
            if(!j) break;
            j--;
        }
        cout << count << endl;
    }

    return 0;
}
