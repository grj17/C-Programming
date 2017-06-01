#include"./bintree.h"

static int height(struct node *root, int height);

void mirror(struct node *root)
{
	if(root == NULL)
		return;
	else{
		struct node *temp;
		mirror(root->left);
		mirror(root->right);
		
		temp = root->right;
		root->right = root->left;
		root->left = temp;
	}
}

int same_struct(struct node *root1, struct node *root2)
{
	if((root1 == NULL) && (root2 == NULL))
	{
		return true;
	} else if(root1 && root2){
		/* Tree structure is same, data may be different */
		int l_same;
		int r_same;
		l_same = same_struct(root1->left, root2->left);
		r_same = same_struct(root1->right, root2->right);
		return (l_same && r_same);
	} else {
		return false;
	}
}

int same_tree(struct node *root1, struct node *root2)
{
	if((root1 == NULL) && (root2 == NULL))
	{
		return true;
	} else if(root1 && root2){
		int l_same;
		int r_same;
		if(root1->data == root2->data){
			l_same = same_tree(root1->left, root2->left);
			r_same = same_tree(root1->right, root2->right);
			return (l_same && r_same);
		} else {
			return false;
		}
	} else {
		return false;
	}
}

int height(struct node *root, int ht)
{
	if(root == NULL)
		return ht;
	else {
		int height_l;
		int height_r;
		height_l = height(root->left, ht+1);
		height_r = height(root->right, ht+1);
		return (height_l > height_r ? height_l : height_r);
	}
}
int height_rec(struct node *root)
{
	return height(root, 0);
}
int height_itr(struct node *root)
{
	struct node *node_list1[100];
	struct node *node_list2[200];
	int list1_len = 0;
	int list2_len = 0;
	int height = 0;
	
	if(root == NULL)
		return 0;
	
	node_list1[list1_len] = root;
	list1_len++;
	height++;
	
	while(list1_len || list2_len){
		if(list1_len){
			while(list1_len > 0){
				if(node_list1[list1_len-1]->left){
					node_list2[list2_len] = node_list1[list1_len-1]->left;
					list2_len++;
				}
				if(node_list1[list1_len-1]->right){
					node_list2[list2_len] = node_list1[list1_len-1]->right;
					list2_len++;
				}
				list1_len--;
			}
			height++;
		}
		if(list2_len){
			while(list2_len > 0){
				if(node_list2[list2_len-1]->left){
					node_list1[list1_len] = node_list2[list2_len-1]->left;
					list1_len++;
				}
				if(node_list2[list2_len-1]->right){
					node_list1[list1_len] = node_list2[list2_len-1]->right;
					list1_len++;
				}
				list2_len--;
			}
			height++;
		} 
	}
	return (height-1);
}