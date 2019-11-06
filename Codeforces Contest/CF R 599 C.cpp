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
        if()
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
        for(int i = 0; i < n - 1; i ++){ //here n - 1 because last time no need to swap
            if(findInLowStr(i) >= 0){
            }
            else if(findInSameStr[i] >= 0){

            }
            else{
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    return 0;
}
