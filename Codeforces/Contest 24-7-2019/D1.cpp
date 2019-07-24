#include<bits/stdc++.h>
using namespace std;
int min(int a , int b){
    return a < b ? a : b;
}
int main(){
    int t;
    string line;
    string patternA = "RGB", patternB = "GBR", patternC = "BRG";
    cin >> t;
    while(t--){
        int n, k, j, minAns = 1000000;
        cin >> n >> k;
        cin >> line;
        int araA[n],araB[n],araC[n];
        for(int i = 0; i < n; i++){
            araA[i] = 0, araB[i] = 0, araC[i] = 0;
            if(line[i] != patternA[i%3]) araA[i] = 1;
            if(line[i] != patternB[i%3]) araB[i] = 1;
            if(line[i] != patternC[i%3]) araC[i] = 1;
            if(i){
                araA[i] += araA[i-1];
                araB[i] += araB[i-1];
                araC[i] += araC[i-1];
            }
        }
/*
        for(int i = 0; i < n; i++)
            cout << " " << araA[i];
        cout << endl;
        for(int i = 0; i < n; i++)
            cout << " " << araB[i];
        cout << endl;
        for(int i = 0; i < n; i++)
            cout << " " << araC[i];
        cout << endl;
*/
        int minA, minB, minC;

        minA = araA[k-1];
        minB = araB[k-1];
        minC = araC[k-1];
        minAns = min(minA,minAns);
        minAns = min(minB,minAns);
        minAns = min(minC,minAns);
        for(int i = 1; i < n-k+1; i++){
            minA = araA[i+k-1] - araA[i-1];
            minB = araB[i+k-1] - araB[i-1];
            minC = araC[i+k-1] - araC[i-1];
            minAns = min(minA,minAns);
            minAns = min(minB,minAns);
            minAns = min(minC,minAns);
        }

        cout << minAns << endl;
    }

    return 0;
}
