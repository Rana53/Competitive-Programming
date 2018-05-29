#include<bits/stdc++.h>
using namespace std;

int convertIndvCharValue(char *line){
    int len = strlen(line);
    set<char>myset(line,line+len);
    set<char>::iterator it;
    int value = 0;
    for (it=myset.begin(); it!=myset.end(); ++it){
       value += *it;
    }
    cout << endl;
    return value;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    char line[n][1000];
    for(int i =0; i < n; i++)
        cin >> line[i];

    set<int> valueContainer;
    for(int i = 0; i < n; i++){
       int parsValue = convertIndvCharValue(line[i]);
       valueContainer.insert(parsValue);
    }
    cout << valueContainer.size() << endl;

    return 0;
}
