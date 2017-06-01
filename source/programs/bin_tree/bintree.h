#include<stdio.h>
#include<stdlib.h>
/* Binary tree node */
struct node {
	int data;
	struct node *left;
	struct node *right;
};

#if !defined(NULL)
#define NULL (void*)0
#endif
#if !defined(false)
#define false 0
#define true  (!false)
#endif



/* Insert data in tree */
void insert(struct node **root,  /* in: root of tree */
		    int data);			 /* in: data to insert */
			
/* Delete data from tree */			
void delete(struct node **root, /* in: root of tree */
		    int data);			/* in: data to delete */
			
/* Lookup a data in the tree and returns the node */			
struct node * lookup(struct node *root, /* root of tree */
					 int data);			/* data to lookup */

/* Returns number of nodes in the tree */					 
unsigned int size(struct node *root);

void print_inorder(struct node *root);
void print_postorder(struct node *root);
void print_preorder(struct node *root);
void print_paths(struct node *root);

unsigned int max_depth(struct node *root);
int max_value(struct node *root);
int min_value(struct node *root);
int has_path_sum(struct node *root, int sum);

void mirror(struct node *root);
int same_struct(struct node *root1, struct node *root2);
int same_tree(struct node *root1, struct node *root2);
int height_rec(struct node *root);
int height_itr(struct node *root);
/* Type safe macro to allocate node */
#define get_node(data) \
({ \
    __typeof__(data) _data = (data); \
    struct node *node = (struct node*)calloc(1, sizeof(struct node)); \
    node->data = _data; \
    node; \
    })

#define put_node(node) \
do{ \
    struct node * _node = node; \
    if(_node) \
        free(_node); \
}while(0)

