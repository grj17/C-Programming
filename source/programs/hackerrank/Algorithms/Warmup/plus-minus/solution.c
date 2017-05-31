#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int arr_i;
    int zeroes = 0;
    int negs = 0;
    scanf("%d",&n);
    int arr[n];
    for(arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    for(arr_i = 0; arr_i < n; arr_i++){
       if(arr[arr_i] > 0) continue;
       if(arr[arr_i] < 0){
           negs++;
           continue;
       }
       zeroes++;
    }
    printf("%.6f\n",(double)(n-(zeroes + negs))/n);
    printf("%.6f\n",(double)negs/n);
    printf("%.6f\n",(double)zeroes/n);
    
    
    return 0;
}

