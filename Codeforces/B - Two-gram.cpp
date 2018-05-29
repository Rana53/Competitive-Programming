#include<bits/stdc++.h>
using namespace std;
int main(){
   int n, len;
   cin >> n;
   string line;
   cin >> line;
   len = line.size();
   map<string,int> value;
   map<string,int> :: iterator it;

   for(int i = 0; i < len-1; i++){
      string tmp="";
      tmp += line[i];
      tmp += line[i+1];
     // cout << tmp << endl;

      value[tmp]++;
   }
   int mx = -1;

   string mx_str;

   for(it = value.begin(); it!=value.end(); ++it)
       if(it->second > mx){
            mx = it->second;
            mx_str = it->first;
       }

    cout << mx_str << endl;

   return 0;
}