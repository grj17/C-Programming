#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void roundoff(int g_size, int* grades) {
    int ext = 0;
    int* _g = grades;
    
    for (int ctr = 0; ctr < g_size; ctr++) {
        if (*_g > 37) {
            ext = *_g % 5;
            *_g += (ext > 2) ? 5 - ext : 0;
        }
        _g++;
     }
 }

int main() {
    int n; 
    scanf("%d", &n);
    int *grades = malloc(sizeof(int) * n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       scanf("%d",&grades[grades_i]);
    }
    
    roundoff(n, grades);
    for(int result_i = 0; result_i < n; result_i++) {
        if(result_i) {
            printf("\n");
        }
        printf("%d", grades[result_i]);
    }
    puts("");
    

    return 0;
}

