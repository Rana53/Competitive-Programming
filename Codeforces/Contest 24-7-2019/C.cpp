#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
    return a < b ? a : b;
}
int main(){
    string line;
    string match = "RGB";
    int t;
    cin >> t;
    while(t--){
        int n, k, count, ii,mn = 100000;
        cin >> n >> k;
        cin >> line;
        for(int i = 0; i < n-k+1; i++){

            for(ii = 0; ii < 3;ii++){
            count = 0;
            for(int j = i; j < i+k; j++){
                if(line[j] != match[ii])
                    count++;
                ii++;
                if(ii == 3) ii = 0;
            }
            mn = min(mn, count);
            }
        }
        cout << mn << endl;
    }

    return 0;
}
