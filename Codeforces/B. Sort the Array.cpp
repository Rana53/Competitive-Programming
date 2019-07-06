#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ara[n];
    map<int,int> element;
    map<int,int> ::iterator it;
    for(int i = 0; i < n; i++){
        cin >> ara[i];
        element[ara[i]];
    }
    int val = 1, start, end;
    for(it = element.begin(); it != element.end(); it++){
        it->second = val;
        val++;
    }
    for(int i = 0; i < n - 1; i++){
        start = i;
        end = i;
        while((ara[i] > ara[i+1]) && (i < n - 1) && (element[ara[i+1]-element[i]] == 1)){
            i++;
            end = i;
        }
        if(start != end) break;
    }
    if(start != end){
        cout << "yes" << endl;
        cout << start << " " << end << endl;

    }
    else
        cout << "no" << endl;
    return 0;
}
