#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int s; 
    int t; 
    scanf("%d %d",&s,&t);
    int a; 
    int b; 
    scanf("%d %d",&a,&b);
    int m; 
    int n; 
    scanf("%d %d",&m,&n);
    int *apple = malloc(sizeof(int) * m);
    for(int apple_i = 0; apple_i < m; apple_i++){
       scanf("%d",&apple[apple_i]);
    }
    int *orange = malloc(sizeof(int) * n);
    for(int orange_i = 0; orange_i < n; orange_i++){
       scanf("%d",&orange[orange_i]);
    }
    
    /* Apple */
    int hs = (s - a);
    int he = (t - a);
    int apps = 0;
            
    for(int apple_i = 0; apple_i < m; apple_i++){
       if((hs <= apple[apple_i]) && (apple[apple_i] <= he)) apps++;
    }
          
    /* Orange */
    hs = (b - s);
    he = (b - t);
    int oras = 0;
            
    for(int orange_i = 0; orange_i < n; orange_i++){
       if((hs >= (-orange[orange_i])) && ((-orange[orange_i]) >= he)) oras++;
    }
    printf("%d\n%d\n", apps, oras);
          
    
    return 0;
}

