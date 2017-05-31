#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n, i, j;
    char *c;
    scanf("%d",&n);
    c = malloc(n);
    memset(c,'#',n);
    for (i = 0, j = n-1; i < n; i++,j--) {
        if(j)
           printf("%*c%.*s\n",(j),' ',n-j, c);
        else
           printf("%.*s\n",n-j, c);
    }
    return 0;
}

