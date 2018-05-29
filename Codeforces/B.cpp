#include<bits/stdc++.h>
using namespace std;
int main(){
    long long ara[14];
    long long mx = -1000;

    for(int i = 0; i < 14; i++)
        cin >> ara[i];

    for(int i = 0; i < 14; i++){
        long long newArr[14];
        long long each , rem;
        each = ara[i] / 14;
        rem = ara[i] % 14;

        for(int j = 0; j < 14; j++)
            newArr[j] = ara[j] + each;
        newArr[i] = each;

        int ind = i + 1;
        for(int j = 0; j < rem; j++){
            if(ind>=14)
                ind = 0;
            newArr[ind]++;
            ind++;
        }

        long long total = 0;
        for(int j = 0; j < 14; j++)
            if(newArr[j]%2 == 0)
                total += newArr[j];

        if(mx<total)
            mx = total;
    }

    cout << mx << endl;

    return 0;
}
