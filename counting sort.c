#include<stdio.h>

void countingSort(int ar[],int size )
{
    int output[10];
    int max=ar[0];
    for(int i=0;i<size;i++)
    {
        if (ar[i]>max)
        {
            max=ar[i];
        }
    }
    int count[10];
    for (int i=0;i<=max;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        count[ar[i]]++;
    }
    for(int i=1;i<=size;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=size-1;i>=0;i--)
    {
        output[--count[ar[i]]]=ar[i];
       //count[ar[i]]--;
    }
    for(int i=0;i<size;i++)
    {
        ar[i]=output[i];
    }

}
void printArray(int ar[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
}
int main()
{

  //int array[] = {4, 2, 2, 8, 3, 3, 1};
 // int n = sizeof(array) / sizeof(array[0]);
  //printf("Enter the n vaslue : %d\n",n);
   int num;
    printf("Enter the size of the array : ");

    scanf("%d",&num);
    int array[num];
    for(int i=0;i<num;i++)
    {
        scanf("%d",&array[i]);
    }
  countingSort(array, num);
  printArray(array, num);
  return 0;

}
