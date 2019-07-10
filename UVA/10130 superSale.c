//accepted
#include<stdio.h>
#include<string.h>

#define MAX 1000
int price[MAX];
int weight[MAX];
int dp[MAX][31];
int CAP;
int n;

int max(int a, int b){
    return a < b ? b : a;
}
int knapsack(int i, int w){
    int profit1 , profit2;
    profit1 = 0;
    profit2 = 0;
    if( i == n )  return 0;
    if(dp[i][w] != -1) return dp[i][w];
    if(w + weight[i] <= CAP)
        profit1 = price[i] + knapsack(i+1,w+weight[i]);
    profit2 = knapsack(i+1,w);
    dp[i][w] = max(profit1,profit2);
    return dp[i][w];
}
int main(){
    int t, g, i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i = 0; i < n; i++)
            scanf("%d %d",&price[i],&weight[i]);
        scanf("%d",&g);
        int maxValOfGood = 0;
        for(i = 0; i < g; i++){
            memset(dp,-1,sizeof(dp));
            scanf("%d",&CAP);
            maxValOfGood += knapsack(0,0);
        }
        printf("%d\n",maxValOfGood);
    }

    return 0;
}

/*
2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26
*/
