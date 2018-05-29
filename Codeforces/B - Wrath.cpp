#include<bits/stdc++.h>
using namespace std;
bool alivePeople[1000005];
int clawLen[1000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i;
    cin >> n;
    for(int a = 0; a < n; a++)
        cin >> clawLen[a];
    i = n-1;
    while(i>0){
        int tmp = i - clawLen[i];
        int j = i-1;
        for( ; (j >= tmp && j >= 0); j--){
            if((j-clawLen[j]) < tmp)
                tmp = j - clawLen[j];
            alivePeople[j] = true;
        }
        i = tmp;
        if(i>=0){
            if(!clawLen[i])
                i--;
        }
    }

    int count = 0;
    for(int a = 0; a < n; a++){
        if(!alivePeople[a]) count++;
    }
    cout << count << endl;
    return 0;
}
/*
12
0 0 0 0 0 1 0 1 2 4 5 5
*/

/*
    while(i > 0){
        int tmp = i - clawLen[i];
        int j = i - 1;
        bool fast = true;
        while(tmp <=j && j>=0){
            if((j-clawLen[j]) < (i-clawLen[i])){
                tmp = (j - clawLen[j]);
            }
            alivePeople[j] = true;
            j--;
        }
        if(clawLen[i])
            i = tmp;
        else i--;
    }

    */