#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string line;
    string match = "RGB"
    cin >> t;
    while(t--){
        int n, k, j;
        cin >> n >> k;
        int ara[n];
        j  = 0;
        ara[0] = 0;
        int prev = 0;
        for(int i = 0; i < n; i++){
            if(line[i] != match[j]){
                ara[i] += prev + 1;
                prev = ara[i];
            }
        }

    }

    return 0;
}
