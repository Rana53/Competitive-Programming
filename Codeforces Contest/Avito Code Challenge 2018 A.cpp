#include<bits/stdc++.h>
using namespace std;
bool isPalindrom(string line){
    int len = line.size();
    string compLine = line;
    reverse(line.begin(), line.end());
    if(line.compare(compLine) == 0) return true;
    else return false;
}
bool sameCharacter(string line){
    int len = line.size();
    for(int i = 1; i < len; i++){
        if(line[0] != line[i]) return false;
    }
    return true;
}
int main(){
    string line;
    cin >> line;
    if(isPalindrom(line)){
        if(sameCharacter(line))
            cout << 0 << endl;
        else
            cout << line.size() - 1 << endl;
    }
    else
        cout << line.size() << endl;

    return 0;
}
