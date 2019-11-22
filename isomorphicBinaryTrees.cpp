#include<iostream>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* newnode(int x)
{
	node* temp= new node();
	temp->data=x;
	temp->right=temp->left=NULL;
	return temp;
}

node* insert(node* root, int x)
{
	if(root==NULL)
	{
		return newnode(x);
	}
	
	node* temp=newnode(x);
	if(x<=root->data)
	{
		root->left=insert(root->left,x);
	}
	else
	{
		root->right=insert(root->right,x);
	}
	
	return root;
}

node* search(node* root, int x)
{
	if(root==NULL)
	return NULL;
	
	if(root->data==x)
	{
		return root;
	}
	
	else if(root->data<x)
	{
		return search(root->right,x);
	}
	
	else
	{
		return search(root->left,x);
	}
}

bool isomorphic(node* root1, node* root2)
{
	if(root1==NULL && root2==NULL)
	{
		return true;
	}
	if(root1!=NULL || root2!=NULL)
	{
		return false;
	}
	if(root1->data!=root2->data)
	{
		return false;
	}
	if((isomorphic(root1->left, root2->left) && isomorphic(root1->right, root2->right)) || (isomorphic(root1->left, root2->right)&& isomorphic(root1->right, root2->left)))
	return true;
	else return false;
}


