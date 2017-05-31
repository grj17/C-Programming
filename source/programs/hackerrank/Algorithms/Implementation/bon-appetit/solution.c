#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int *items = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &items[i]);
    
    int charge;
    scanf("%d",&charge);
    
    int sum = 0;
    
       
    for(int i = 0; i < n; i++){
        if (i == k) continue;
        sum += items[i];
    }
 
    if(charge == sum/2)
        printf("Bon Appetit");
    else if(charge > sum/2) {
        printf("%d",charge - (sum/2));
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

