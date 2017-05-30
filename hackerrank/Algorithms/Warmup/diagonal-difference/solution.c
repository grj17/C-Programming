#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main(){
    int n, diff = 0; 
    int a_i, a_j;
    scanf("%d",&n);
    int a[n][n];
    for(a_i = 0; a_i < n; a_i++){
       for(a_j = 0; a_j < n; a_j++){
          scanf("%d",&a[a_i][a_j]);
       }
    }
    for(a_i = 0, a_j = n-1; a_i < n; a_i++, a_j--){
        diff += (a[a_i][a_i] - a[a_i][a_j]);
    }
    printf("%u",(unsigned int)(diff < 0) ? -diff : diff);
    
    
    return 0;
}

