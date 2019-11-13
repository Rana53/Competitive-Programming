#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, x, a, b, mx, x1, x2, res;
        scanf("%d %d %d %d",&n, &x, &a, &b);
        if(a > b){
            mx = a;
            a = b;
            b = mx;
        }
        x1 = a - 1;
        x2 = n - b;
        res = ((x1+x2)>x)? x: ((x1+x2));
        res = res + (b-a);
        printf("%d\n",res);
    }

    return 0;
}
