#include<stdio.h>

unsigned int count_set_bits(unsigned int a)
{
	unsigned int count = 0;
	while (a) {
		a &= (a-1);
		count++;
	}
	return count;
}

int main()
{
 	unsigned int a = 0u;
        
	printf("----------------Count set bits----------------\n");
	printf("Enter any integer(hex) : 0x");
        scanf("%x", &a);

        printf("a= 0x%x set bits %u\n", a, count_set_bits(a));
	return 0;
}
