#include<stdio.h>
#include<string.h>
int main(){
    char line[500001];
    int t, i, j, n, m, col[500001], maxStrInRow, count,maxStrInCol,bigRow,bigCol;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        memset(col,0,m*sizeof(int));
        maxStrInRow = 0;
        maxStrInCol = 0;
        bigRow = -1;
        bigCol = -1;

        for( i = 0; i < n; i++){
            scanf("%s",line);
            count = 0;
            for( j = 0; j < m; j++){
                if(line[j] == '*'){
                    count++;
                    col[j]++;
                }
            }
            if(maxStrInRow < count)
                maxStrInRow = count;
        }
        for(j = 0; j < m; j++){
            if(col[j] > maxStrInCol)
                maxStrInCol = col[j];
        }
        printf()
        printf("%d\n",(m+n)-(maxStrInCol+maxStrInRow-1));
    }

    return 0;
}
