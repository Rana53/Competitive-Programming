#include<bits/stdc++.h>
using namespace std;
int main(){
   string str,cpy="aabb";
   int n,b=1;
   cin>>n;
   int j=0;
   for(int i=0;i<n;i++){
      str+=cpy[j++];
      if(j==4) j=0;
   }
   cout<<str<<endl;

   return 0;
}