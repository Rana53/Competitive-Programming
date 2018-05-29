#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;
int main(){
   set < int >lantarn;
   set < int > :: iterator it;
   int n,l,x,first,second;
   double dis;

   cin>>n>>l;
   for(int i=0;i<n;i++){
     cin>>x;
     lantarn.insert(x);
   }
   it=lantarn.begin();
   first=(*it);
   dis=0.0;

   for(it++;it!=lantarn.end();it++){
     second=(*it);
     if(((second-first)/2.0)>dis) dis=(second-first)/2.0;
     first=second;
   }

   if((l-first)>dis) dis=l-first;
   it=lantarn.begin();
   if(((*it)-0)>dis) dis=(*it)-0;

   printf("%.10lf\n",dis);

   return 0;
}