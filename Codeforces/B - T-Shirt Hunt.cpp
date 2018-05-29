#include<iostream>
using namespace std;
int p;
bool unsuccess_hack(int n);

int main(){
   int y,x,sHack=0;
   bool hack=false;
   cin>>p>>y>>x;

   for(int i=y;i>=x;i=i-50){
      hack=unsuccess_hack(i);
      if(hack){
         cout<<0<<endl;
         return 0;
      }
   }

   int lim=y;
   while(1){
      sHack++;
      lim+=100;
      hack=unsuccess_hack(lim);
      if(hack){
         cout<<sHack<<endl;
         return 0;
      }
      hack=unsuccess_hack(lim-50);
      if(hack){
         cout<<sHack<<endl;
         return 0;
      }
   }

   return 0;
}

bool unsuccess_hack(int n){
   long long s=(n/50)%475;
   for(int i=0;i<25;i++){
        s=((s*96)+42)%475;
        if((s+26)==p) return true;

   }
   return false;
}