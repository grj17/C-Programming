#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int a[] = {0, 0};

int* solve(int a0, int a1, int a2, int b0, int b1, int b2, int *result_size){
    if (a0 != b0){
        if (a0 > b0)
            a[0]++;
        else 
            a[1]++;
    }
    
    if (a1 != b1){
        if (a1 > b1)
            a[0]++;
        else 
            a[1]++;
    }
    
    if (a2 != b2){
        if (a2 > b2)
            a[0]++;
        else 
            a[1]++;
    }
    *result_size = 2;
    return a;
}

int main() {
    int a0; 
    int a1; 
    int a2; 
    scanf("%d %d %d", &a0, &a1, &a2);
    int b0; 
    int b1; 
    int b2; 
    scanf("%d %d %d", &b0, &b1, &b2);
    int result_size = 0;
    int* result = solve(a0, a1, a2, b0, b1, b2, &result_size);
    for(int result_i=0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    

    return 0;
}
