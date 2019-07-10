#include<stdio.h>
#include<string.h>
#define MX 6
int coin [] = {50, 25, 10, 5, 1};
int make;
int dp[MX][7490];

int knapsack(int i , int amount){
    if(i >= 5)
        return amount == make;
    if(dp[i][amount] != -1) return dp[i][amount];
    int ret1, ret2;
    ret1 = 0;
    ret2 = 0;
    if(amount + coin[i] <= make)
        ret1 = knapsack(i, amount + coin[i]);
    ret2 = knapsack(i+1,amount);
    return dp[i][amount] = ret1 + ret2;
}

int main(){
    while(scanf("%d",&make) != EOF){
        memset(dp, -1, sizeof(dp));
        long long int count;
        count = knapsack(0,0);
        printf("%d\n",count);
    }
    return 0;
}
