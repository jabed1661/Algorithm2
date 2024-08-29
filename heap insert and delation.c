
#include<stdio.h>
int size = 0;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void heapify(int ar[],int size,int i)
{
    if(size==1)
    {
        printf("Single element\n");
    }
    else
    {

        int largest=i;
        int left = 2*i+1;
        int right =2*i+2;
        if (left<size && ar[left]>ar[largest])
        {
            largest=left;
        }
         if (right<size && ar[right]>ar[largest])
        {
            largest=right;
        }
        if(largest!=i)
        {
            swap(&ar[i],&ar[largest]);
            heapify(ar,size,largest);
        }
    }


}
void insert(int ar[],int new_number)
{
    if (size==0)
    {
        ar[size]=new_number;
        size+=1;
    }
    else
    {
        ar[size]= new_number;
        size+=1;
        for(int i=size/2-1; i>=0; i--)
        {
            heapify(ar,size,i);
        }
    }
}
void delate_data(int ar[],int data)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(data==ar[i])
        {
            int max=ar[i];
            printf("The deleting data is : %d\n",max);
            break;
        }
    }
    swap(&ar[i],&ar[size-1]);
    size-=1;
    for(i=size/2-1;i>=0;i--)
    {
        heapify(ar,size,i);
    }

}
void print(int ar[],int size)
{
    for (int i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
}
int main()
{
    int num;
    printf("Enter the size of the array : ");
    int ar[10];
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&ar[i]);
        insert(ar,ar[i]);
    }
    /*
    int ar[10];
    insert(ar,3);
    insert(ar,4);
    insert(ar,9);
    insert(ar,5);
    insert(ar,2);*/
    printf("The map heap of the array is : \n");
    print(ar,size);
    int digit;
    printf("\nEnter the value which are deleting in the list:");
    scanf("%d",&digit);
    printf("\nAfter deleting data the array list is :\n");
    delate_data(ar,digit);
    print(ar,size);




    return 0;
}
