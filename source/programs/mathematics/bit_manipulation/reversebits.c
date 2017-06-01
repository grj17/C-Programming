#include<stdio.h>

/* in a loop */
unsigned int reverse_bits(unsigned int a)
{
	unsigned int reversed = 0;
	int ctr = (sizeof(a)*8);
	while (a) {
		reversed <<= 1;
		reversed |= (1 & a);
		a >>= 1;
		ctr--;
	}
	if (ctr) reversed <<= ctr;
	return reversed;
}

/* without loop */
unsigned int reverse_bits_no_loop(unsigned int x)
{
    /* works for 4 bytes only */
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
    return x;
}

int main()
{
	unsigned int a = 0u;

	printf("----------------Reverse bits----------------\n");
	printf("Enter any integer(hex) to reverse: 0x");
	scanf("%x", &a);
        printf("Data = 0x%x, reversed = 0x%x, 0x%x\n", a, reverse_bits(a), reverse_bits_no_loop(a));
	return 0;
}
