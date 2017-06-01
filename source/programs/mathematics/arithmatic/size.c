#include<stdio.h>
	struct grj{
		int i;
		int j;
		char a;
	};

int size(struct grj ig[])
{
 printf("sssize: %d\n", sizeof(ig));
 printf("sssize: %d\n", sizeof(ig[0]));
	return sizeof(ig)/sizeof(ig[0]);
}

int main()
{
 struct grj igr[5];
 printf("size: %d\n", size(igr)/size(igr));

}
