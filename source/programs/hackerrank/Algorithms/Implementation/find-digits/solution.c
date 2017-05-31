#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int find_digits(unsigned int num)
{
    int count = 0;
    int n_num = num;
    while(n_num){
        int rem = n_num % 10u;
        if (rem && ((num % rem) == 0)){
            count++;
        }
        n_num /= 10;
    }
    return count;
}
int main(){
    int t; 
    scanf("%d",&t);
    int n[t]; 
    for(int a0 = 0; a0 < t; a0++){
        scanf("%d",&n[a0]);
    }
    for(int a0 = 0; a0 < t; a0++){
        printf("%d\n", find_digits(n[a0]));
    }
    return 0;
}

