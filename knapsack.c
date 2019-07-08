///this tutorial is covered from shafayet blog
#include<stdio.h>
#define MAX_c 100
#define MAX_w 1000
int n;
int weight[MAX_c];
int cost[MAX_c];
int dp[MAX_c][MAX_w];
int CAP;
int max(int a, int b){
    return a > b ? a: b;
}
int knapsack(int i , int w ){
    int profit1, profit2;
    profit1 = 0;
    profit2 = 0;
    if(i == n) return 0;
    if(dp[i][w]!=-1)  return dp[i][w];
    if(weight[i]+w <= CAP)
        profit1 =cost[i] + knapsack(i+1, w+weight[i]);
    profit2 = knapsack(i+1,w);
    dp[i][w] = max(profit1, profit2);
    return dp[i][w];

}

int main(){
    scanf("%d %d",&n, &CAP);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)
        scanf("%d %d",&cost[i],&weight[i]);
    printf("%d", knapsack(0, 0));
    return 0;
}
