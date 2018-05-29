#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    int n, one =0, zero = 0;
    cin >> n;
    cin >> line;
    for(int i =0; i < n; i++)
        if(line[i]=='0') zero++;
    one = n - zero;
    if(one >= 2)
        for(int i = 1; i < one; i++)
            cout << 1;
    else
        cout << 1
    return 0;
}
