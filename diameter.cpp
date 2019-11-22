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


int height(node* root)
{
	if(root==NULL)
	return 0;
	int left=height(root->left);
	int right=height(root->right);
	return max(left,right)+1;
}

int diameter(node* root)
{
	if(root==NULL)
	return 0;
	int left = height(root->left);
	int right = height(root->right);
	return left+right+1;
}

int diameterofbt(node* root)
{
	if(root==NULL)
	return 0;
	
	int main=diameter(root);
	int left = diameter(root->left);
	int right = diameter(root->right);
	
	int a= max(left, right);
	int b= max(a, main);
	return b;
}

int main()
{
	node* root=NULL;
	root= insert(root,50);
	root=insert(root,90);
	root=insert(root,45);
	root=insert(root,30);
	root=insert(root,110);
	root=insert(root,46);
	root=insert(root,85);
	
	int result=diameterofbt(root);
	cout<<result;
	return 0;
}

