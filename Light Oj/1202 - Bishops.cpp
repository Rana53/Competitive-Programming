#include<iostream>
#include<cmath>
using namespace std;
int main(){
   int r1,c1,r2,c2;
   int n,i;
   i=1;
   cin>>n;
   while(i<=n){
     cin>>r1>>c1>>r2>>c2;
     int rem_r;
     int rem_c;
     rem_r=abs(r1-r2);
     rem_c=abs(c1-c2);
     cout<<"Case "<<i++<<": ";
     if(rem_r%2==rem_c%2){
        if(abs(r1-r2)==abs(c1-c2))
            cout<<1<<endl;
        else
            cout<<2<<endl;
     }
     else{
        cout<<"impossible\n";
     }
   }
 
   return 0;
}
 