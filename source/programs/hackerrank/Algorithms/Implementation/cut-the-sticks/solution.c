nclude <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/* Quick sort */
int pivot(int arr[], int lo, int hi)
{
    int pivot = hi;
    int i, j;
    j = lo;
    for(i = lo; i < hi; i++)
    {
        if(arr[i] <= arr[pivot]){
            swap(&arr[i] , &arr[j]);
            j++;
        }
    }
    swap(&arr[j] , &arr[pivot]);
    return j;
}
void quick_sort(int arr[], int lo, int hi)
{
    int p = 0;
    if(lo < hi){
        p = pivot(&arr[0], lo, hi);
        quick_sort(&arr[0], lo, p - 1);
        quick_sort(&arr[0], p + 1, hi);
    }
}

void stick_cuts(int arr[], int n)
{
    int i = 0;
    unsigned int cut_size = arr[i];
    
    printf("%d\n", n);
    while( cut_size < arr[n-1]){
        while(arr[i] <= cut_size) i++;
        printf("%d\n",n-i);
        cut_size += (arr[i] - cut_size);
    }
}


int main(){
    int n; 
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    quick_sort(&arr[0], 0, n - 1);
    stick_cuts(&arr[0], n);
    return 0;
}

