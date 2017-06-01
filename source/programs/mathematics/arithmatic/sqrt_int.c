/* Square root using integer arithmetic */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int int_sqrt(unsigned long num, unsigned int *sqrt)
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
                }else if(sqr < num) {
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


int main()
{
	unsigned int sqrt = 0;
	int_sqrt(1000000000ul, &sqrt);
    printf("Square Root: %u\n", sqrt);
    return 0;
}

