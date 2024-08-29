
#include<stdio.h>
#include<limits.h> //for INT_MAX
int coin_change(int coins[],int num_of_coins,int amount)
{
    int dp[amount+1];
    for (int i=0;i<=amount;i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0]=0;
    for(int i=0;i<num_of_coins;i++)
    {
        for (int j=coins[i];j<=amount;j++)
        {
            dp[j]=dp[j]<dp[j-coins[i]]+1? dp[j]: dp[j-coins[i]]+1;
            /*if (dp[j]< dp[j-coins[i]]+1)
            {
                dp[j] = dp[j];
            }
            else
            {
                dp[j] = dp[j-coins[i]]+1;
            }*/
        }
    }
    return dp[amount]==INT_MAX? -1:dp[amount];
}
int main()
{
    int coins[]={1,2,5};
    int num_of_coins=sizeof(coins)/sizeof(coins[0]);
    int amount;
    printf("Enter the amount  :");
    scanf("%d",&amount);
    int result = coin_change(coins,num_of_coins,amount);
    //printf("The minimum number of coins change : ");
    if (result == -1)
    {
        printf("It's not possible to make the amount %d with the given coins.\n", amount);
    }
    else
    {
        printf("Minimum number of coins needed to make change for %d: %d\n", amount, result);
    }
}
