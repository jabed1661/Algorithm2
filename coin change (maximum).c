#include<stdio.h>
int coin_change(int coins[],int size,int amount)
{
    int dp[amount+1];
    for (int i=0;i<=amount;i++)
    {
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<size;i++)
    {
        for(int j=coins[i];j<=amount;j++)
        {
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[amount];
}
int main()
{
    int coins[]={1,2,5};
    int size=sizeof(coins)/sizeof coins[0];
    int amount;
    printf("Enter the amount : ");
    scanf("%d",&amount);
    int x = coin_change(coins,size,amount);
    printf("The maximum coins change of ways is : ");
    printf("%d ",x);
    return 0;
}
