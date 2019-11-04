#include<stdio.h>
int main(){
    int t, a, b, n, s, div;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&a, &b, &n, &s);
        div = s / n;
        if (div > a)
            div = a;
        if (((div*n)+b) >= s)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
