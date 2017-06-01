#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int find_min_w(int *arr, int ent, int ex)
{
    int i = ent + 1;
    int j = ex;
    int min = arr[ent];
    while(j >= i) {
        min = (min < arr[i]) ? min : arr[i];
        min = (min < arr[j]) ? min : arr[j];
        if(min == 1) break;
        i++; j--;
    }
    return min;
}

int main(){
    int n; 
    int t; 
    scanf("%d %d",&n,&t);
    int width[n];
    int entry_p[t];
    int exit_p[t];
    
    for(int width_i = 0; width_i < n; width_i++){
       scanf("%d",&width[width_i]);
    }
    for(int a0 = 0; a0 < t; a0++){
        scanf("%d %d",&entry_p[a0],&exit_p[a0]);
        printf("%d\n", find_min_w(&width[0], entry_p[a0], exit_p[a0]));
    }
    return 0;
}

