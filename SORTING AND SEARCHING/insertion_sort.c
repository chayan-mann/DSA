// In insertion sort, the input array is also divided into two parts: a sorted part and an unsorted part.
// The algorithm picks up an element from the unsorted part and places it in the correct position in the sorted part, shifting the larger elements one position to the right.
// Insertion sort has a time complexity of O(n^2) in the worst case, but can perform better on partially sorted arrays, with a best-case time complexity of O(n).

// ALGORITHM :=
// To sort an array of size N in ascending order iterate over the array and compare the current element (key) to its predecessor, if the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.


#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}

void InsertionSort(int A[], int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j = i -1;
        x=A[i];
        while(A[j]>x && j> -1)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
int main ()
{	
int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
InsertionSort(A,n);
for(i=0;i<10;i++)
printf("%d ",A[i]);
printf("\n");
return 0;
}