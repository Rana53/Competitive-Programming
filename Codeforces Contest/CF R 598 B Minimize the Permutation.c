#include<stdio.h>
int main(){
    int q, n, ara[100],i;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", &ara[i]);
        }
        int  minValuePos, initialPos, tmp, minFound;
        initialPos = 0;

       for(i = 0; i < n; ){
           minFound = 0;
           minValuePos = i;
           for(int j = i ; j < n; j++ ){
               if(ara[minValuePos] > ara[j]){
                   minFound = 1;
                   minValuePos = j;
               }
           }

           tmp = ara[minValuePos];
           for(int j = minValuePos; j > i; j--)
               ara[j] = ara[j-1];
            ara[i] =  tmp;
           if(minFound) i = minValuePos;
           else i++;

           }


        printf("%d",ara[0]);
        for(i = 1; i < n; i++){
            printf(" %d", ara[i]);
        }
        printf("\n");
    }

    return 0;
}
