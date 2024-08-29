#include<stdio.h>
void merge(int ar[],int fi,int mid,int li)//fi=first index.li=list index
{
    int i = fi;
    int j=mid+1;
    int k=0;
    int temp[li-fi+1];
    while(i<=mid &&j<=li)
    {
        if(ar[i]<=ar[j])
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

    for(k=0,i=fi; i<=  li;i++, k++)
    {
        ar[i]=temp[k];
    }

}

void merge_short(int ar[],int fi,int li)
{
    if (fi<li)
    {
        int mid= (fi+li)/2;
        merge_short(ar,fi,mid);
        merge_short(ar,mid+1,li);
        merge(ar,fi,mid,li);

    }
}
int main() {
    int num;
    printf("Enter the size of array: ");
    scanf("%d", &num);

    int ar[num];
    printf("Enter the elements of the array: ");

    for (int i = 0; i < num; i++) {
        scanf("%d", &ar[i]);
    }

    merge_short(ar, 0, num - 1);

    printf("The sorted array: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");

    return 0;
}

