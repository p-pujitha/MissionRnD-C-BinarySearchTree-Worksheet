/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
struct node * insert(struct node *, int);
//struct node *deletee(struct node *, int);
struct node *singleLrot(struct node *);
struct node *singleRrot(struct node *);
struct node *doubleLR(struct node *);
struct node *doubleRL(struct node *);
void preorder(struct node *);
void inorder(struct node *);
int avlht(struct node *);
struct node * array_to_bst(int *arr, int start, int end);
struct node * create_root(int num);
/* one method is to add the node and find the balance of that node 
	2nd method is to divide the array in 2 parts and find the mid of the array attach the element  it to the tree */

#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};


struct node * convert_array_to_bst(int *arr, int len){
	
	/*struct node *bt=NULL;
	if (len <= 0 || arr == NULL)
		return NULL;
	else
	{
		for (int i = 0; i < len;i++)
			bt=insert(bt, arr[i]);
		return bt;

	}*/

	if (arr == NULL)
		return NULL;
	return array_to_bst(arr, 0, len - 1);
	
}

struct node * array_to_bst(int *arr, int start, int end)
{
	int mid = (start + end) / 2;
	struct node *root;
	if (start <= end)
	{
		root = create_root(arr[mid]);
		root->left = array_to_bst(arr, start, mid - 1);
		root->right = array_to_bst(arr, mid + 1, end);
		return root;

	}

}

struct node * create_root(int num)
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root->data = num;
	root->left = NULL;
	root->right = NULL;
	return root;

}

/*
struct node * insert(struct node *p, int a)
{
	if (p == NULL)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a;
		p->left = NULL;
		p->right = NULL;

	}
	else
	{
		if (a<p->data)
		{
			p->left= insert(p->left, a);
			if (avlht(p->left) - avlht(p->right) == 2)
			{
				if (a< p->left->data)
					p = singleRrot(p);
				else
					p = doubleLR(p);
			}
		}
		else if (a> p->data)
		{
			p->right = insert(p->right, a);
			if (avlht(p->right) - avlht(p->left) == 2)
			{
				if (a > p->right->data)
					p = singleLrot(p);
				else
					p = doubleRL(p);
			}
		}
	}
	return p;
}



int avlht(struct node *p)
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


struct node * singleLrot(struct node *p1)
{
	struct node *p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	return p2;
}

struct node * singleRrot(struct node *p1)
{
	struct node *p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	return p2;
}

struct node * doubleLR(struct node *p)
{
	p->left = singleLrot(p->left);
	p = singleRrot(p);
	return p;
}

struct node * doubleRL(struct node *p)
{
	p->right = singleRrot(p->right);
	p = singleLrot(p);
	return p;
}

*/
