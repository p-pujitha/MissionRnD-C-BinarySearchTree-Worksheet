/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6   0                     <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int avlht(struct node *p)		// Calculating the height of the particular node
{
	if (p == NULL)
		return 0;
	else
	{
		int ldepth = avlht(p->left);
		int rdepth = avlht(p->right);
		if (ldepth >rdepth)
			return ldepth + 1;
		else
			return rdepth + 1;
	}
}

void array_with_right_to_left_values(struct node* root, int level, int *arr, int *len)
{
	if (root == NULL)
		return ;
	if (level == 1){
		//printf("%d\t", root->data);
		arr[*len] = root->data;
		*len += 1;
	}
	else 
	{
		array_with_right_to_left_values(root->right, level - 1, arr, len);
		array_with_right_to_left_values(root->left, level - 1, arr, len);
	}

}



void traverse_right_to_left(struct node *root, int *arr)
{

	int height = avlht(root);
	int pos = 0;
	
	for (int i = 1; i <= height; i++)
	{
		 array_with_right_to_left_values(root, i, arr, &pos);
		
	}
}


int* BSTRighttoLeftRows(struct node* root)

{
	if (root == NULL)
		return NULL;
	else
	{
		int *arr = (int *)malloc(sizeof(int)*40);
		
		traverse_right_to_left(root, arr);
		return arr;
		
	}

    
}
