#include<stdio.h>

int max(int a,int b)
{
    return (a>b)?a:b;
}
int knapsack(int value[],int wl[],int capacity,int size)
{
    int dp[size+1][capacity+1];
    for (int i=0;i<=size;i++)
    {
        for(int w=0 ;w<=capacity;w++)
        {
            if(i==0 || w==0)
            {
                dp[i][w]=0;
            }
            else if(wl[i-1]<=w)
            {
                dp[i][w]= max(dp[i-1][w],dp[i-1][w-wl[i-1]]+value[i-1]);
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[size][capacity];
}
int main()
{
    int size;
    printf("Enter the size :");
    scanf("%d",&size);
    int capacity;
    printf("Enter the capacity of the product :");
    scanf("%d",&capacity);
    int value[size],wl[size];
    for (int i=0;i<size;i++)
    {
        printf("Item %d:\n",i+1);
        printf("Enter the weight:");
        scanf("%d",&wl[i]);
        printf("Enter the value: ");
        scanf("%d",&value[i]);

    }
    int max_profits= knapsack(value,wl,capacity,size);
        printf("The maximum profits of the knapsack : %d\n",max_profits);

}
