#include<iostream>
#include<string>
#include<map>
using namespace std;

bool digit(char s);

int main(){
    map<char,int> VALUE;
	string str1,str2,str;
    cin>>str1>>str2>>str;
    
	for(int i=0;i<26;i++){
    	VALUE[str1[i]]=i;
	}
    
	int L;
    L=str.size();
    
	for(int i=0;i<L;i++){
   
       if(digit(str[i])){
       	   cout<<str[i];
	   }

	   else{
	   	    if(str[i]>='A' && str[i]<='Z'){
	   	    	str[i]=str[i]-'A'+'a';
	   	    	str[i]=str2[VALUE[str[i]]];
	   	    	str[i]=str[i]-'a'+'A';
	   	    	cout<<str[i];
		    }
		    else{
		    	cout<<str2[VALUE[str[i]]];
			}
	   }

	}
   
   return 0;
}

bool digit(char s){
   
	switch(s){
		
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
	    case '9':
	    	return true;
	    	
	    default:
		    return false;
	} 
}