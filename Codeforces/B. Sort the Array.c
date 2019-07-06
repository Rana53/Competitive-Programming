///C code don't get any solution

#include<stdio.h>
int main(){
    int n, start, end;
    scanf("%d",&n);
    int ara[n], revAra[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &ara[i]);
        revAra[i] = ara[i] * -1 ;
    }
    for(int i = n - 1; i >= 0; i--){
        start = i;
        end = i;
        while((ara[i] < ara[i-1]) && (i != 0)){
            i--;
            start = i;
        }
        if( start != end)
            break;
    }

    if(start != end){
        printf("yes\n");
        printf("%d %d\n", start + 1, end + 1);
    }
    else
        printf("no\n");

    return 0;
}
