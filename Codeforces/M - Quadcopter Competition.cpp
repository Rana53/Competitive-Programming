#include <bits/stdc++.h>
using namespace std;

int absolute(int n){
    if(n<0)
        return -n;
    return n;
}

int main(){
    int x1, y1, x2, y2;

    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=-1){
        int dist = absolute(x1-x2) + absolute(y1-y2);
        if(x1==x2 || y1==y2)
            printf("%d\n",dist*2+6);

        else
            printf("%d\n",dist*2+4);
    }

    return 0;
}