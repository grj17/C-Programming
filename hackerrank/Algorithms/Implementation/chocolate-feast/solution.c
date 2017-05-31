#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* Dollor to choco */
#define D2C(d, p)   ((d)/(p))

/* wrapper to choco */
int w2c(int wc, int wpc)
{
    if(wc < wpc){
        return 0;
    }    
    return ((wc/wpc) + w2c( ((wc/wpc) + wc%wpc), wpc));
}

int main(){
    int t; 
    int chocos = 0;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        int c; 
        int m; 
        scanf("%d %d %d",&n,&c,&m);
        chocos = D2C(n, c);
        chocos += w2c(chocos, m);
        printf("%d\n", chocos);
    }
    return 0;
}

