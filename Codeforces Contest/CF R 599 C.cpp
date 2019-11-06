#include<bits/stdc++.h>
using namespace std;
int str1, str2;
int n;
int findInLowStr(int i){
    for(int j = i; j < n; j++){
        if(str2[j] == str[i]) return j;
    }
    return -1;
}

int findInLowStr(int i){
    for(int j = i + 1; j < n; j++){

    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cin >> str1;
        cin >> str2;
        for(int i = 0; i < n; i ++){
            if(findInLowStr(i)){
            }
            else if(findInSameStr[i])
        }
    }
    return 0;
}
