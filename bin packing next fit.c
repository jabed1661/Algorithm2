#include<stdio.h>

#define MAX 100
int bin_packing(int weight[],int size,int capacity)
{
    int bin_count=1;
    int bin_space=capacity;
    for (int i=0;i<size;i++)
    {
        if (bin_space>=weight[i])
        {
            bin_space-=weight[i];
        }
        else
        {
            bin_count++;
            bin_space=capacity-weight[i];
        }
    }
    return bin_count;
}
int main()
{
    int size;
    printf("Enter the size of digit: ");
    scanf("%d",&size);
    int weight[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&weight[i]);
    }
    int capacity;
    printf("Enter the capacity: ");
    scanf("%d",&capacity);
    int result = bin_packing(weight,size,capacity);
    printf("The bin packing of next fit is : ");
    printf("%d",result);

}
