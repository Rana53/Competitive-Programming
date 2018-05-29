#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
   optimize();
   int pos=1e9,n;
   cin>>n;
   int ara[n],ans[n];

   for(int i=0;i<n;i++) cin>>ara[i];

   for(int i=0;i<n;i++){
      if(!ara[i]) pos=i;
      ans[i]=(pos==1e9)?pos:i-pos;
   }

   pos=1e9;

   for(int i=n-1;i>=0;i--){
      if(!ara[i]) pos=i;
      ans[i]=pos-i<ans[i]?pos-i:ans[i];
   }

   cout<<ans[0];
   for(int i=1;i<n;i++) cout<<" "<<ans[i];
   cout<<endl;
   return 0;
}