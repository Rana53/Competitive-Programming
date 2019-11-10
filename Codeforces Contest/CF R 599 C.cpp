#include<bits/stdc++.h>
using namespace std;
string str1, str2;
int n;

int findCharPosition(int i, int lebel, char ch){
    if(lebel == 1){
        for(int j = i; j < n ;j++){
            if (ch == str1[j])
                return j;
        }
    }
    else{
        for(int j = i; j < n ;j++){
            if (ch == str2[j]){
                return j;
            }

        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        bool solutionPossible = true;
        int charPos;
        cin >> n;
        cin >> str1;
        cin >> str2;
        pair <int, int> myPair[n*2];
        int pairCount = 0;
        for(int i = 0; i < n; i ++) {
            if(str1[i] == str2[i]) continue;
            char tmp;
            int charPos = findCharPosition(i+1, 2, str2[i]);
             //cout <<"First" << charPos << endl;
            if (charPos >= 0) {
                tmp = str2[charPos];
                str2[charPos] = str1[i];
                str1[i] = tmp;
                myPair[pairCount++] = make_pair(i, charPos);
            } else {
                charPos = findCharPosition(i, 1, str2[i]);
                //cout << charPos << endl;
                if(charPos < 0){
                   // cout <<i<< "----------" << str1 << str2 << endl;
                    solutionPossible = false;
                    break;
                }
                tmp = str1[charPos];
                str1[charPos] = str2[charPos];
                str2[charPos] = str1[i];
                str1[i] = tmp;
                myPair[pairCount++] = make_pair(charPos, charPos);
                myPair[pairCount++] = make_pair(i, charPos);
            }

        }
        if (!solutionPossible){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << pairCount << endl;
            for (int i = 0; i < pairCount; i++) {
                cout << myPair[i].first+1 << " " << myPair[i].second+1 << endl;
            }
        }
    }
    return 0;
}
