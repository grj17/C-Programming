#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int s[3][3];
    for(int s_i = 0; s_i < 3; s_i++){
       for(int s_j = 0; s_j < 3; s_j++){
          
          scanf("%d",&s[s_i][s_j]);
       }
    }
    
    int magic[8][3][3] = {{{4,9,2}, {3,5,7}, {8,1,6}},
                         {{8,1,6}, {3,5,7}, {4,9,2}},
                         {{4,3,8}, {9,5,1}, {2,7,6}},
                         {{2,9,4}, {7,5,3}, {6,1,8}},
                         {{6,7,2}, {1,5,9}, {8,3,4}},
                         {{6,1,8}, {7,5,3}, {2,9,4}},
                         {{2,7,6}, {9,5,1}, {4,3,8}},
                         {{8,3,4}, {1,5,9}, {6,7,2}}};
        ;
    int min_cost = 100;
    int curr_cost = 0;
        
    for (int m = 0; m < 8; m++) {
        curr_cost = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                curr_cost += abs(magic[m][i][j] - s[i][j]);
            }
        }
        if (curr_cost < min_cost) min_cost = curr_cost;
     }
    
    printf("%d\n",min_cost);
    return 0;
}

