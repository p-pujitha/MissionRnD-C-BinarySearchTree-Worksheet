/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>
void sum_left(struct node *, int *);
void sum_right(struct node *, int *);

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int get_height(struct node *root){
	if (root == NULL)
		return 0;
	else
	{
		int ldepth = get_height(root->left);
		int rdepth = get_height(root->right);
		if (ldepth >rdepth)
			return ldepth + 1;
		else
			return rdepth + 1;
	}

	
}

int get_left_subtree_sum(struct node *root){
	
	if (root == NULL)
		return NULL;

	int sum = 0;
	sum_left(root->left, &sum);
	return sum;

	
	
}

int get_right_subtree_sum(struct node *root){

	if (root == NULL)
		return NULL;
	int sum = 0;
	sum_right(root->right, &sum);
	return sum;
	
}

void sum_left(struct node *root, int *sum)
{
	if (root != NULL){
		sum_left(root->left, sum);
		*sum = *sum + root->data;
		sum_left(root->right, sum);
	}
}

void sum_right(struct node *root, int *sum)
{
	if (root != NULL){
		sum_right(root->left, sum);
		*sum = *sum + root->data;
		sum_right(root->right, sum);
	}
}