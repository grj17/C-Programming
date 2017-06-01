#include"./bintree.h"

static void find_node(struct node *root,     	/* in: root node of tree/sub tree */
			   int data,				/* in: Data to search */
			   struct node **node, 		/* out: node to find */
			   struct node **parent)	/* out: parent of node to find */
{
		if(root == NULL){
			(*parent) = NULL;
			(*node) = NULL;
		} else if (root->data == data){
			(*node) = root; 
		} else if (root->data > data){
			(*parent) = root;
			find_node(root->left, data, node, parent);
		} else {
			(*parent) = root;
			find_node(root->right, data, node, parent);
		}
}

void insert(struct node **root,  /* in: root of tree */
		    int data)			 /* in: data to insert */
{
		struct node * node=get_node(data);
		if((*root) == NULL) {
			(*root) = node;
			return;
		}
		if(data >= (*root)->data)
			insert(&(*root)->right, data);
		else
			insert(&(*root)->left, data);
}


void delete(struct node **root, /* in: root of tree */
		    int data)			/* in: data to delete */
{
		struct node *node = NULL;
		struct node *parent = NULL;
		
		find_node(*root, data, &node, &parent);
		
		if(node == NULL)
			return;
		
		/* if node to be deleted is a leaf */
		if((node->left == NULL) && (node->right == NULL)) {
			if(parent == NULL) {
				/* Single node tree */
				(*root)=NULL;
			} else {
				if(parent->left == node)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
		} else if(node->left && node->right) {
			/* if it has both the children
			   find replacer from left subtree */
			struct node *replacer = node->left;
			struct node *rep_parent = NULL;
			
			/* right most from left subtree */
			while (replacer->right) {
				rep_parent = replacer;
				replacer = replacer->right;
			}
			/* replace node */
			if(parent){
				if(parent->left == node)
					parent->left = replacer;
				else
					parent->right = replacer;
			} else {
				*root = replacer;
			}
			replacer->right = node->right;
			if(rep_parent)
				rep_parent->right = replacer->left;
			if(replacer != node->left)
			replacer->left = node->left;
		} else if(node->left) {
			/* if it has only left child */
			if(parent){
				if(parent->left == node)
					parent->left = node->left;
				else
					parent->right = node->left;
			} else {
				*root = node->left;
			}
		} else {
				/* if it has only right child */
			if(parent){
				if(parent->left == node)
					parent->left = node->right;
				else
					parent->right = node->right;
			} else {
				*root = node->right;
			}
		}
		free(node);
}

int main()
{
	int data[15] = {10,5,15,6,16,4,14,7,3,17,11,12,18,2,1};
	int data1[15] = {10,5,15,6,16,4,14,7,3,17,11,12,18,2,1};
	struct node *root = NULL;
	struct node *root1 = NULL;
	struct node *node = NULL;
	int i = 0;
	
	
	printf("\nINPUT DATA\n");
	for(i=0; i<15; i++)
		printf("%d, ",data[i]);

	for(i=0; i<15; i++)
		insert(&root, data[i]);
	
	printf("\n\nIN-ORDER traversal:\n");
	print_inorder(root);
	
	printf("\n\nPRE-ORDER traversal:\n");
	print_preorder(root);
	
	printf("\n\nPOST-ORDER traversal:\n");
	print_postorder(root);
	
	printf("\n\nPATHS:\n");
	print_paths(root);

	printf("\n\nLOOK-UP:25\n");
	node = lookup(root,25);
	if(node)
		printf("Found:%d\n",node->data);
	else
		printf("Can not find 25!!\n");
	
	printf("\n\nLOOK-UP:12\n");
	node = lookup(root,12);
	if(node)
		printf("Found:%d\n",node->data);
	else
		printf("Can not find 25!!\n");
	
	printf("\n\nSIZE:\n");
	printf("Size of tree:%u\n", size(root));
	
	printf("\n\nMIN VALUE:\n");
	printf("Minimum:%u\n", min_value(root));
	
	printf("\n\nMAX VALUE:\n");
	printf("Maximum:%u\n", max_value(root));
	
	printf("\n\nHAS PATH SUM:62\n");
	printf("Path sum:%d\n", has_path_sum(root, 62));
	
	printf("\n\nHAS PATH SUM:80\n");
	printf("Path sum:%d\n", has_path_sum(root, 80));
		
	printf("\n\nIN_ORDER after MIRROR:\n");
	mirror(root);
	print_inorder(root);
	
	printf("\n\nIN_ORDER after MIRROR undo:\n");
	mirror(root);
	print_inorder(root);

	for(i=0; i<15; i++)
	{
		insert(&root1, data1[i]);
	}
	printf("\n\n SAME STRUCT:\n");
	printf("SAME:%d\n",same_struct(root, root1));
	
	printf("\n\n SAME TREE:\n");
	printf("SAME:%d\n",same_tree(root, root1));
	
	printf("\n\n DELETE 18 from tree 1:\n");
	delete(&root, 18);
	//printf("SAME STRUCT:%d\n",same_struct(root, root1));
	
	printf("\n\n INSERT 19 in tree 1:\n");
	insert(&root, 19);
	printf("\n\n SAME STRUCT:\n");
	printf("SAME:%d\n",same_struct(root, root1));
	
	printf("\n\n SAME TREE:\n");
	printf("SAME:%d\n",same_tree(root, root1));
	
	

	printf("\n\n HEIGHT-R:\n");
	printf("Height:%d\n",height_rec(root));
	
	printf("\n\n HEIGHT-I:\n");
	printf("Height:%d\n",height_itr(root));


	printf("\n\n IN-ORDER after DELETE all\n");
	for(i=0; i<15; i++)
	{
		delete(&root1, data[i]);
	}
	print_inorder(root1);

	for(i=0; i<15; i++)
	{
		printf("\n\n IN-ORDER after DELETE %d\n", data[i]);
		delete(&root, data[i]);
		print_inorder(root);
	}
	
	printf("\n");
	
}
