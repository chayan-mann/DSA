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

struct Array* Merge(struct Array  *arr1,struct Array *arr2)
{
    int i=0, j=0,k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]= arr1->A[i++];
        else
            arr3->A[k++]= arr2->A[j++];
    }

    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i++];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j++];
        arr3->length = arr1->length + arr2->length;
        arr3->size =10;

        return arr3;
}
int main ()
{	
    struct Array arr1={{2,4,6,8,10},10,5};
    struct Array arr2={{1,3,5,7,9},10,5};
    struct Array *arr3;
    arr3 = Merge(&arr1,&arr2);

    Display(*arr3);
return 0;
}