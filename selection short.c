#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b= temp;
}
void selection_short(int ar[],int num)
{
    for(int i=0; i<num-1; i++)
    {
        int min =i;
        for(int j=i+1; j<num; j++)
        {
            if(ar[j]<ar[min])
            {
                min=j;
            }
        }
        if (min!=i)
        {
            swap(&ar[i],&ar[min]);
        }

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
    selection_short(ar,num);
    printf("The shorting list of array : ");
    for(int i=0; i<num; i++)
    {
        printf("%d ",ar[i]);
    }
}

