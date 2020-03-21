#include<bits/stdc++.h>
using namespace std;
void goDamaPrint(int n){
    if(n < 5){
        cout << "O-";
    }
    else{
        cout << "-O";
    }
}
void ichiDamaPrint(int n){
    for(int i = 0; i < n; i++){
        cout << "O";
    }
    cout << "-";
    for(int i = n + 1; i < 5; i++){
        cout << "O";
    }
    cout << endl;
}
int main(){
    int n, d;
    cin >> n;
    do{
        d = n % 10;
        n = n / 10;
        goDamaPrint(d);
        cout << "|";
        ichiDamaPrint(d%5);
    }while(n);
    return 0;
}
