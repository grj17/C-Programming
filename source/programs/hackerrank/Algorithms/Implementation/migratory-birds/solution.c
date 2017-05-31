#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int *types = malloc(sizeof(int) * n);
    for(int types_i = 0; types_i < n; types_i++){
       scanf("%d",&types[types_i]);
    }
    
    int type_ctr[6] = {0};
        
    for(int i = 0; i < n; i++)
        type_ctr[types[i]]++;
    
    int max_id = 1;
    for(int i = 2; i <= 5; i++) {
         if(type_ctr[i] > type_ctr[max_id]) max_id = i;
    }
        
    printf("%d", max_id);
    
    return 0;
}
