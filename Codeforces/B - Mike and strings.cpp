#include<bits/stdc++.h>
using namespace std;

int acompare(string &s1,string &s2);

int main(){

   string str[50];
   int n,l,mn=1000000,change=0;
   cin>>n;

   for(int i=0;i<n;i++)
     cin>>str[i];

   l=str[0].size();

   string ms,rs;
   ms=str[0];

   for(int i=0;i<l;i++){
      change=i;
      if(i){
         char ch;
         ch=ms[0];
         ms.erase(0,1);
         ms+=ch;
      }
      for(int j=1;j<n;j++){
         int a;
         rs=str[j];
         a = acompare(ms,rs);
         if(a==-1){
            cout<<a<<endl;
            return 0;
         }
         else{
            change += a;
         }
      }
      if(change<mn) mn=change;
   }

   cout<<mn<<endl;

   return 0;
}

int acompare(string &s1,string &s2){
   int l=s1.size(),count=0;
   bool flag=false;
   for(int i=0;i<l;i++){
      if(i){
        char ch;
        ch=s2[0];
        s2.erase(0,1);
        s2+=ch;
      }
      if(s1==s2){
        count=i;
        flag=true;
        break;
      }
   }
   if(flag) return count;
   else return -1;
}