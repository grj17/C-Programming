#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void min_max(int *arr)
{
    unsigned long sum = 0;
    int min = *arr;
    int max = *arr;
        
    for(int ctr = 0; ctr < 5; ctr++) {
        sum += *arr;
        min = (*arr < min) ? *arr : min;
        max = (*arr > max) ? *arr : max;
        arr++;
    }
    printf("%lu %lu\n", (sum - max), (sum - min));
}

int main() {
    int *arr = malloc(sizeof(int) * 5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    
    min_max(arr);
    return 0;
}

