#include<stdio.h>
void swap(int *x,int *y)
{
    int tmep=*x;
    *x=*y;
    *y=tmep;
}
int patition(int ar[],int fi,int li)//li=last index,fi=first index;
{
    int privot=ar[fi];
    int i = fi;
    int j =li;
    while(i<j)
    {
        while(i<=li&&ar[i]<=privot)
        {
            i++;
        }
        while(ar[j]>privot)
        {
            j--;
        }
        while(i<j)
        {
            swap(&ar[i],&ar[j]);
        }
    }
    swap(&ar[fi],&ar[j]);
    return j;

}
void quickshort(int ar[],int fi,int li)
{
    if(fi<li)
    {
        int loc=patition(ar,fi,li);
        quickshort(ar,fi,loc-1);
        quickshort(ar,loc+1,li);
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
    // patition(ar,0,num);
    quickshort(ar,0,num-1);
    printf("The shorting list of array : ");
    for(int i=0; i<num; i++)
    {
        printf("%d ",ar[i]);
    }
}
