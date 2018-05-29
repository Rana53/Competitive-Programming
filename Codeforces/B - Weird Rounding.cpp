#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,x,c=0,r=0;
    char n[12];
    cin>>n>>k;
    x=strlen(n);

    for(int i=0;i<x;i++)
        if(n[i]=='0') c++;
    if(c<k) cout<<x-1<<endl;

    else {
            c=0;
        for(int i=x-1;i>=0;i--){
        if(n[i]=='0') c++;
        else r++;
        if(c==k) break;
        }
        cout<<r<<endl;
    }
return 0;
}