#include<stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b= temp;
}

int main()
{
    int num;
    printf("Enter the size of array : \n");
    scanf("%d",&num);
    int ar[num];
    for  (int i=0;i<num;i++)
    {
        scanf("%d",&ar[i]);
    }
    for (int i=0;i<num-1;i++)
    {
       for(int j=0;j<num-i-1;j++)
       {
           if(ar[j]>ar[j+1])
           {
              swap(&ar[j],&ar[j+1]);
           }
       }
    }
    for(int i=0;i<num;i++)
    {
        printf("%d ",ar[i]);
    }
}
