#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int arr_i, arr_j;
    int sum = 0;
    scanf("%d",&n);
    int arr[n];
    for(arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    arr_i--;
    for(arr_j = 0; arr_j < arr_i; arr_i--, arr_j++){
       sum += (arr[arr_j] + arr[arr_i]);
    }
    sum += (arr_j == arr_i) ? arr[arr_j] : 0;
    printf("%d", sum);
    return 0;
}

