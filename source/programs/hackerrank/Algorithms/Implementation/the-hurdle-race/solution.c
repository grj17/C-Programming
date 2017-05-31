#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int max(int *height, int len)
{
    unsigned int max = 0;
    
    for (int ctr = 0; ctr < len; ctr++) {
            max = (*height > max) ? *height : max;
            height++;
        }

    return max;
}

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *height = malloc(sizeof(int) * n);
    for(int height_i = 0; height_i < n; height_i++){
       scanf("%d",&height[height_i]);
    }
    int mx  = max(height, n);
    printf("%d\n", (mx > k) ? (mx - k) : 0);
    return 0;
}

