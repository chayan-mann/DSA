#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\n Elements are:\n");
    for(i=0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
}

void Append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x= arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i]= arr->A[i-1];
        arr->length--;
        return x;
    }
    return 0;
}

void InsertSort(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}
int main ()
{	
    struct Array arr={{2,3,15,17,30}, 10,5};

    //InsertSort(&arr,4);
    printf("%d \n", isSorted(arr));
    // Insert(&arr,5,10);
    Display(arr);
return 0;
}