#include<stdio.h>
void merge(int ar[],int fi,int li,int mid)
{
    int i=fi;
    int j= mid+1;
    int k=0;
    int temp[li-fi+1];
    while(i<=mid && j<=li)
    {
        if (ar[i]<=ar[j])
        {
            temp[k]=ar[i];
            i++;
        }
        else
        {
            temp[k]=ar[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k]=ar[i];
        i++;
        k++;
    }
    while(j<=li)
    {
        temp[k]=ar[j];
        j++;
        k++;
    }
    for (k=0,i=fi;i<=li;i++,k++)
    {
        ar[i]=temp[k];
    }
}
void marge_sort(int ar[],int fi,int li)
{
    if (fi<li)
    {
            int mid = (li+fi)/2;

        marge_sort(ar,fi,mid);
        marge_sort(ar,mid+1,li);
        merge(ar,fi,li,mid);

    }
}
void print(int ar[],int size)
{
    printf("the final list of the marge_sort is : ");
    for (int i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
}
int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    int ar[size];
    printf("Enter the data : ");
    for (int i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
    marge_sort(ar,0,size-1);
    print(ar,size);
   /* printf("The sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");*/

    return 0;

}
