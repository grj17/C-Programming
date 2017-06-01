#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void printRecord(int s_size, int* s){
    int min = s[0];
    int max = s[0];
    int min_count = 0;
    int max_count = 0;
    
    for (int i = 1; i < s_size; i++) {
        if(s[i] < min) {
            min = s[i];
            min_count++;
        } else if (s[i] > max) {
            max = s[i];
            max_count++;
        }
    }
    printf("%d %d\n", max_count, min_count);
    
}

int main() {
    int n; 
    scanf("%d",&n);
    int *s = malloc(sizeof(int) * n);
    for(int s_i = 0; s_i < n; s_i++){
       scanf("%d",&s[s_i]);
    }
    printRecord(n, s);
    
    return 0;
}

