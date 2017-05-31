#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int int_sqrt(unsigned int num, unsigned int *sqrt)
{
        /* using binary search */
        unsigned int low = 0;
        unsigned int high = num;
        unsigned int mid = 0;
        unsigned long long sqr = 0;
    
        if(num == 1) {
            *sqrt = 1;
            return 0;
        }
            
        
        while(high - low)
        {
                mid = (high + low)/2;
                if(mid == low) break;
                sqr = (unsigned long long)mid*mid;
                if(sqr > num) {
                        high = mid;
                        continue;
                }
                if(sqr < num) {
                        low = mid;
                        continue;
                }else{
                        
                        *sqrt = mid;
                        /* Prfect */
                        return 0;
                }
        }
        /* floor */
        *sqrt = mid;
        return 1;
}

unsigned int sherlock_sqr(unsigned int low, unsigned int high)
{
        unsigned int sqrt_low;
        unsigned int sqrt_high;

        if(int_sqrt(low, &sqrt_low)) sqrt_low++;
        int_sqrt(high, &sqrt_high);
        if(sqrt_high < sqrt_low) return 0;
        return (sqrt_high - sqrt_low + 1);

}


int main() 
{
   int t = 0;
   scanf("%d",&t);
   int n[t][2];
   for(int i = 0; i < t; i++)
       scanf("%u %u",&n[i][0], &n[i][1]);
    
   for(int i = 0; i < t; i++)
       printf("%u\n", sherlock_sqr(n[i][0], n[i][1]));
   return 0;
}

