#include"./bintree.h"

struct node * lookup(struct node *root, /* root of tree */
					 int data)			/* data to lookup */
{
	if(root == NULL){
		return NULL;
	} else if (root->data > data){
		return lookup(root->left, data);
	} else if (root->data < data){
		return lookup(root->right, data);
	} 
	return root;
}

unsigned int size(struct node *root)
{
	if(root == NULL)
		return 0;
	return (size(root->left) + size(root->right) + 1);
}

unsigned int max_depth(struct node *root)
{
	if (root == NULL)
		return 0;
	else {
		unsigned int left_depth = max_depth(root->left);
		unsigned int right_depth = max_depth(root->right);
		if(left_depth > right_depth) 
			return (left_depth + 1);
		else 
			return (right_depth + 1);
	}
}

int min_value(struct node *root)
{
	if(root != NULL) {
		while(root->left){
			root = root->left;
		}
		return root->data;
	}
	return 0xBADBEAF;
}

int max_value(struct node *root)
{
	if(root != NULL) {
		while(root->right){
			root = root->right;
		}
		return root->data;
	}
	return 0xBADBEAF;	
}

int has_path_sum(struct node *root, int sum)
{
	if(root == NULL){ 
		return (sum ==0);
	} else {
		int new_sum = sum - root->data;
		return (has_path_sum(root->left, new_sum) ||
			    has_path_sum(root->right, new_sum));
	}
}