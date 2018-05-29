#include<bits/stdc++.h>
using namespace std;

string Grid[100];
int Check[100][100];

void fillWithColumn(int n, int k);
void fillWithRow(int n, int k);

int main(){
    int n, k;
    cin >> n >> k;
    int mx_col, mx_row, mx_value = -100;
    for(int i = 0; i < n; i++)
        cin >> Grid[i];
    fillWithColumn(n,k);
    fillWithRow(n,k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(Check[i][j] > mx_value){
                mx_value = Check[i][j];
                mx_row = i;
                mx_col = j;
            }
        }
    }

    cout << (mx_row + 1) << " " << (mx_col + 1) << endl;

    return 0;
}

void fillWithColumn(int n, int k){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n-k; j++){
            if(Grid[i][j] == '.' && Grid[i][j+k-1] == '.'){
                bool vartical = true;
                for(int l = 1; l < k; l++){
                    if(Grid[i][j+l]!='.'){
                        vartical = false;
                        break;
                    }
                }
                if(vartical){
                    for(int l = 0; l < k; l++)
                        Check[i][j+l] += 1;
                }
            }
        }
    }
}

void fillWithRow(int n, int k){
    for(int i = 0; i <= n-k; i++){
        for(int j = 0; j < n; j++){
            if(Grid[i][j] == '.' && Grid[i+k-1][j] == '.'){
                bool horaizotal = true;
                for(int l = 1; l < k; l++){
                    if(Grid[i+l][j]!='.'){
                        horaizotal = false;
                        break;
                    }
                }
                if(horaizotal){
                    for(int l = 0; l < k; l++)
                        Check[i+l][j] += 1;
                }
            }
        }
    }
}