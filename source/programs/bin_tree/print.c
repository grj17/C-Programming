#include"./bintree.h"
void print_inorder(struct node *root)
{
	if (root == NULL)
		return;
	print_inorder(root->left);
	printf("%d, ", root->data);
	print_inorder(root->right);
}
void print_postorder(struct node *root)
{
	if (root == NULL)
		return;
	print_postorder(root->left);
	print_postorder(root->right);
	printf("%d, ", root->data);
	
}

void print_preorder(struct node *root)
{
	if (root == NULL)
		return;
	printf("%d, ", root->data);
	print_preorder(root->left);
	print_preorder(root->right);
}


void paths(struct node *root, int path[], int len)
{
	if(root == NULL){
		return;
	}		
	else if((root->left == NULL) && (root->right == NULL)){
		int i;
		for(i=0; i<len; i++){
			printf("%d, ", path[i]);
		}
		printf("%d\n",root->data);
		return;
	} else {
		path[len] = root->data;
		if(root->left)
			paths(root->left, path, len+1);
		if(root->right)
		paths(root->right, path, len+1);
	}
}

void print_paths(struct node *root)
{
	int path[100];
	paths(root, path, 0);
	
}
