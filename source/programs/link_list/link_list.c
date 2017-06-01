WARNING!!! Under development
#include<stdio.h>

/* Link list node */
typedef struct list {
	unsigned long key;    /* Data */
	struct list *next_p;   /* Next node */
}list_t;

#define INIT_LIST_HEAD() ((list_t *)NULL)
#define _ALLOC_N(node, data) 
	do {
		list_t * _node = (list_t*)(node);
		unsigned long _data = (unsigned long) (data);

		_node = calloc(1, sizeof(*node));
		_node->data = _data;
	} while(0)

#define _DELETE_N(node) 
	do {
		free(node);
	} while(0);

#define LIST_INSERT(key, head)  
	do {
		typeof(data) _data = (data);

		node->next_p = head;
		head = node;
	} while(0)


list_t* list_insert(list_t *head)
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

        printf("Data= 0x%x number of toggle bits %u\n", a, count_toggle_bits(a));
	return 0;
}
