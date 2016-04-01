/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int min(int a, int b);
int avlht(struct node *p);

int search(struct node *p, int a, int root_value, struct node *root, int i)
{

	int distance = 0;					//Find the min distance from leaf to the particular node 
	if (a<p->data)
	{
		i = i + 1;
		search(p->left, a, root_value, root, i);
	}
	if (a == p->data)
	{
		int distance_leaf = avlht(p) - 1;
		//printf("Element found %d \n", a);
		//printf("Height of that node =%d \n", distance_leaf);
		if (a<root_value){
			distance = avlht(root->right);
			//printf("Height of the right subtree of the root= %d\n", distance);
		}
		else if (a>root_value){
			distance = avlht(root->left);
			//printf("Height of the left subtree of the root =%d\n", distance);
		}
		//printf("Height from root to the find node = %d\n", i);
		//printf("Minimum of the distance from leaves to that particular node is %d", min(i + distance, distance_leaf));
		return min(i + distance, distance_leaf);
	}
	if (a>p->data){
		i = i + 1;
		search(p->right, a, root_value, root, i);
	}
}


int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	
	 int min_value= search(root, temp->data, root->data, root, 0);
	 return min_value;
}

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

int min(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}