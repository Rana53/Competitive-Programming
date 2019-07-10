#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 10
int coin[MAX];
int dp[MAX][100];
int make;
int n;
int count = 0;
bool knapsack(int i, int amount){
    if(i >= n){
       return amount == make;
    }

    int ret1, ret2;
    ret1 = 0;
    ret2 = 0;
    if(dp[i][amount] != -1) return dp[i][amount];
    if(amount+coin[i] <= make)
        ret1 = knapsack(i, amount+coin[i]);
    ret2 = knapsack(i+1, amount);
    return dp[i][amount] = ret1 | ret2;
}
int main(){
    int i;
    scanf("%d %d",&n,&make);
    memset(dp,-1,sizeof(dp));
    for(i = 0; i < n; i++)
        scanf("%d",&coin[i]);
    bool isMake = false;
    isMake = knapsack(0,0);
    printf("%d\n",isMake);
    return 0;
}
