#include<bits/stdc++.h>
using namespace std;

int main(){
    string line[50001];
    int t, i, j, n, m, col[500001], maxStrInRow, count,maxStrInCol,posRow,posCol;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        memset(col,0,m*sizeof(int));
        maxStrInRow = 0;
        maxStrInCol = 0;
        posRow = -1;
        posCol = -1;

        for( i = 0; i < n; i++){
            cin >> line[i];
            count = 0;
            for( j = 0; j < m; j++){
                if(line[i][j] == '*'){
                    count++;
                    col[j]++;
                }
            }
            if(maxStrInRow < count){
                maxStrInRow = count;
                posRow = i;
            }
        }
        for(j = 0; j < m; j++){
            if(col[j] > maxStrInCol){
                maxStrInCol = col[j];
                posCol = j;
            }
        }
        if(posCol == posRow && line[posRow][posCol]=='.')
            printf("%d\n",(m+n)-(maxStrInCol+maxStrInRow+1));
        else
            printf("%d\n",(m+n)-(maxStrInCol+maxStrInRow));
    }

    return 0;
}
