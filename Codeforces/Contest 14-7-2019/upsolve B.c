#include<stdio.h>
#include<string.h>
int min(int a, int b){
    return a < b ? a : b;
}
int main(){
    int t, m, n, i, j, total, ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n, &m);
        int row[n];
        int col[m];
        char grid[n][m];
        for(i = 0; i < n; i++){
            scanf("%s",grid[i]);
            row[i] = 0;
        }

        for(j = 0; j < m; j++){
            col[j] = 0;
            for(i = 0; i < n; i++){
                if(grid[i][j] == '.'){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        ans = 1000000000;
        for( i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                total = row[i] + col[j];
                if(grid[i][j] == '.')
                    total -= 1;
                ans = min(ans,total);
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
