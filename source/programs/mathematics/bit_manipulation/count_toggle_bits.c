#include<stdio.h>
/* Using lookup table */
unsigned int toggle[] = {0,1,2,1,1,2,1,0};

unsigned int count_toggle_bits_lookup(unsigned int a)
{
	unsigned int count = 0;
	while (a) {
		count += toggle[a & 0x7u];
		a >>= 2;
	}
	return count;
}

/* Using bit scan */
unsigned int count_toggle_bits(unsigned int a)
{
	unsigned int count = 0;
	while (a) {
		if(((a & 0x3) == 0x2u) || ((a & 0x3) == 0x1u))
			count++;
		a >>= 1;
	}
	return count;
}


int main()
{
 	unsigned int a = 0u;
	printf("----------------Count toggle bits----------------\n");
	printf("NOTE: First bit not considered as toggle bit.\n");
        printf("Enter any integer(hex) : 0x");
        scanf("%x", &a);

        printf("Data= 0x%x number of toggle bits %u, %u\n", a, count_toggle_bits(a), count_toggle_bits_lookup(a));
	return 0;
}
