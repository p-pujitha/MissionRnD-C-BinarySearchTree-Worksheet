/*
Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

void cal_preorder(struct node *root, int *arr, int *i);
void cal_inorder(struct node *, int *, int *);
void cal_preorder(struct node *root, int *arr, int *i);

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder(struct node *root, int *arr){
	int i = 0;
	cal_inorder(root, arr, &i);
}

void cal_inorder(struct node *root, int *arr, int *i)
{
	if (root == NULL && arr == NULL || arr == NULL)
		arr = NULL;

	else if (root == NULL);


	else
	{
		cal_inorder(root->left, arr,i);
		arr[*i] = root->data;
		
			*i = *i + 1;
		
		cal_inorder(root->right, arr,i);
	}
	

	
}

void cal_preorder(struct node *root, int *arr, int *i)
{
	if (root == NULL && arr == NULL || arr == NULL)
		arr = NULL;

	else if (root == NULL);


	else
	{
		
		arr[*i] = root->data;

		*i = *i + 1;
		cal_preorder(root->left, arr, i);

		cal_preorder(root->right, arr, i);
	}

}
void cal_postorder(struct node *root, int *arr, int *i)
{
	if (root == NULL && arr == NULL || arr == NULL)
		arr = NULL;

	else if (root == NULL);


	else
	{

		
		cal_postorder(root->left, arr, i);
		cal_postorder(root->right, arr, i);
		arr[*i] = root->data;

		*i = *i + 1;
	}

}
void preorder(struct node *root, int *arr){
	int i = 0;
	
	cal_preorder(root, arr, &i);
}

void postorder(struct node *root, int *arr){
	int i = 0;
	cal_postorder(root, arr, &i);
}

