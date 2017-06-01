#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

unsigned long ut_growth(int cycles)
{
    if (cycles == 0) return 1;
    if (cycles == 1) return 2;
    if(cycles%2) return (2*ut_growth(cycles-1));
    else return (ut_growth(cycles-1)+1);
}

int main(){
    int t; 
    scanf("%d",&t);
    int n[t];
    for(int a0 = 0; a0 < t; a0++){
        scanf("%d",&n[a0]);
    }
    for(int a0 = 0; a0 < t; a0++){
        printf("%lu\n", ut_growth(n[a0]));
    }
    
    return 0;
}

