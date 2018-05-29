#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    string Grid[n];
    int Check[n][n], mx_col, mx_row, mx_value = -100;
    memset(Check, 0, sizeof(int [n][n]));
    for(int i = 0; i < n; i++)
        cin>> Grid[i];

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(Grid[i][j] == '.'){
                //column operation
                if(j+k <n){
                    bool vartical = true;
                    for(int l = 1; l < k; l++){
                        if(Grid[i][j+l]!='.'){
                            vartical = false;
                        }
                    }
                    if(vartical){
                      //  cout << "col " << i<<"-" << j<<endl;
                        for(int l = 0; l < k; l++){
                            Check[i][j+l] += 1;
                        }
                    }
                }
                if(i+k<n){
                    // horizontal
                    bool horizontal = true;
                    for(int l = 1; l < k; l++){
                        if(Grid[i+l][j]!='.'){
                            horizontal = false;
                        }
                    }
                    if(horizontal){
                       // cout << "col " << i<<"-" << j<<endl;
                        for(int l = 0; l < k; l++){
                            Check[i+l][j] += 1;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            //cout << "  " << Check[i][j];
            if(Check[i][j]> mx_value){
                mx_row = i;
                mx_col = j;
                mx_value = Check[i][j];
            }
        }
        //cout << endl;
    }
    cout << (mx_row+1) << " " << (mx_col+1) << endl;
    return 0;
}
