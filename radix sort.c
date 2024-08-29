#include<stdio.h>

int getmax(int ar[],int num)
{
    int max =ar[0];
    for (int i=1;i<num;i++)
    {
        if (ar[i]>max)
        {
            max=ar[i];

        }
    }
    return max;
}


void radix(int ar[],int num,int  posi)
{
   int output[num+1];
   /*int max=(ar[0]/posi)%10;
   for(int i=1;i<num;i++)
   {
       if (((ar[i]/posi)%10)>max)
       {
           max=ar[i];
       }
   }
   int count[max+1];

   for (int i=0;i<max;++i)
   {
       count[i]=0;
   }*/
   int count[10]={0};
   for (int i=0;i<num;i++)
   {
       count[(ar[i]/posi)%10]++;
   }
   for(int i=1;i<10;i++)
   {
       count[i]+=count[i-1];
   }
   for(int i=num-1;i>=0;i--)
   {
       output[--count[(ar[i]/posi)%10]]=ar[i];
       //output[count[(ar[i] / posi) % 10] - 1] = ar[i];
    //count[(ar[i] / posi) % 10]--;
   }
   for(int i=0;i<num;i++)
   {
       ar[i]=output[i];
   }
}
void radix_sort(int ar[],int num)//value ta ke divide korar jonno
{
    int x= getmax(ar,num);
    for (int posi=1; x/posi>0; posi*=10)
    {
         radix(ar,num,posi);
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
    int ar[num];
    for(int i=0;i<num;i++)
    {
        scanf("%d",&ar[i]);
    }
  radix_sort(ar, num);
  printArray(ar, num);
  return 0;

}

