#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int max_count(int *height, int len)
{
    unsigned int max = 0;
    unsigned int max_ctr = 0;
    
    for (int ctr = 0; ctr < len; ctr++) {
        if (*height >= max) {
            max_ctr = (*height == max) ? (max_ctr + 1) : 1;
            max = *height;
        }
        
        height++;
    }
    return max_ctr;
}

int main(){
    int n;
 
    scanf("%d",&n);
    unsigned int *height = malloc(sizeof(int) * n);
    for(int height_i = 0; height_i < n; height_i++){
       scanf("%d",&height[height_i]);
    }
    
    printf("%d\n", max_count(height, n));
    return 0;
}

