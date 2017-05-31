#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int getWays(int squares_size, int* squares, int d, int m){
    unsigned int sum = 0;
    int counter = 0;
    int s = 0;
    int e = m;
    if (squares_size < m) return 0;
    
    for(int i = 0; i < e; i++)  {
        sum += squares[i];
    }
    if(sum == d) counter++;
    for(int i = e; i < squares_size; i++, s++) {
        sum -= squares[s];
        sum += squares[i];
        if(sum == d) counter++;
    }
    return counter;    
}

int main() {
    int n; 
    scanf("%d",&n);
    int *s = malloc(sizeof(int) * n);
    for(int s_i = 0; s_i < n; s_i++){
       scanf("%d",&s[s_i]);
    }
    int d; 
    int m; 
    scanf("%d %d",&d,&m);
    int result = getWays(n, s, d, m);
    printf("%d\n", result);
    return 0;
}

