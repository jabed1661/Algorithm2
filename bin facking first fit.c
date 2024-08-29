#include<stdio.h>
#define MAX 100
int bit_facking(int weight[],int size,int capacity)
{
    int bit_count= 0;
    int bit_space[MAX];
    for (int i=0;i<size;i++)
    {
        bit_space[i]=0;
    }
    for (int i=0;i<size;i++)
    {
        int j=0;
        for(j=0;j<bit_count;j++)
        {
            if (bit_space[j]>=weight[i])
            {
                bit_space[j]-=weight[i];
                break;
            }
        }
        if (j==bit_count)
        {
            bit_space[bit_count]=capacity-weight[i];
            bit_count++;
        }
    }
    return bit_count;

}
int main()
{
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int weight[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&weight[i]);
    }
    int capacity;
    printf("Enter the bin capacity: ");
    scanf("%d",&capacity);
    int result= bit_facking(weight,size,capacity);
    printf("The minimum bit facking is : ");
    printf("%d\n",result);
}
