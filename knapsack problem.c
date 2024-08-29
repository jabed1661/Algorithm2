#include<stdio.h>
struct Item
{
    int value;
    int weight;
};
void swap(struct Item *a,struct Item *b)
{
    struct Item temp =*a;
    *a = *b;
    *b  = temp;
}
void short_item(struct Item item[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for (int j=i+1;j<size;j++)
        {
           double p1=(double)item[i].value/item[i].weight;
           double p2=(double)item[j].value/item[j].weight;
           if(p1<p2)
           {
               swap(&item[i],&item[j]);
           }
        }
    }
}
double factorial_knapsack(struct Item item[],int capacity,int size)
{
    short_item(item,size);
    int current_weight=0;
    double final_value = 0.0;
    for(int i=0;i<size;i++)
    {
        if(current_weight+item[i].weight<=capacity)
        {
            current_weight+=item[i].weight;
            final_value+=item[i].value;
        }
        else
        {
            int remaing_capacity= capacity-current_weight;
            final_value+=item[i].value*((double)remaing_capacity/item[i].weight);
            break;
        }

    }
    return final_value;
}
int main()
{
    int size;
    printf("Enter the number of the product : ");
    scanf("%d",&size);
    int capacity;
    printf("Enter the capacity of the knapsack : ");
    scanf("%d",&capacity);
    struct Item item[size];
    for (int i=0;i<size; i++)
    {
        printf("Item :%d\n",i+1);
        printf("Enter The value: ");
        scanf("%d",&item[i].value);
        printf("Enter the weight  :");
        scanf("%d",&item[i].weight);
    }
    double result = factorial_knapsack(item,capacity,size);
    printf("The maximum value in knapsack : ");
    printf("%.2f \n",result);
}
