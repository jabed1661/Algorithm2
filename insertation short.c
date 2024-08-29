#include<stdio.h>
int insertion_short(int ar[],int num)
{
    for (int i=1;i<num;i++)
    {
        int temp =ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>temp)
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1] = temp;


    }
}
int main()
{
    int num;
    printf("Enter the size of arrany: ");

    scanf("%d",&num);
    int ar[num];
    printf("Enter the number of array : ");

    for(int i=0; i<num; i++)
    {
        scanf("%d",&ar[i]);
    }
    insertion_short(ar,num);
    printf("The shorting list of array : ");
    for(int i=0; i<num; i++)
    {
        printf("%d ",ar[i]);
    }
}
