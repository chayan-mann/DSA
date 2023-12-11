// Selection sort scans the unsorted part to find the minimum element, while insertion sort scans the sorted part to find the correct position to place the element.
// Selection sort requires fewer swaps than insertion sort, but more comparisons.
// Insertion sort is more efficient than selection sort when the input array is partially sorted or almost sorted, while selection sort performs better when the array is highly unsorted.
// https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.w3resource.com%2Fphp-exercises%2Fsearching-and-sorting-algorithm%2Fsearching-and-sorting-algorithm-exercise-4.php&psig=AOvVaw2muIXOe9D54qkAFJJNwr-F&ust=1698927483664000&source=images&cd=vfe&opi=89978449&ved=0CBIQjRxqFwoTCLjpkJvkooIDFQAAAAAdAAAAABAI

#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}

void SelectionSort(int A[], int n)
{
    int i,j,k;
    for(i=0;i<n-1; i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&(A[i]),&(A[k]));
    }
}

int main ()
{	
int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
SelectionSort(A,n);
for(i=0;i<10;i++)
printf("%d ",A[i]);
printf("\n");
return 0;
}