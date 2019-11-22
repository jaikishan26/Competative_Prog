#include<iostream>
#include<stack>
#include<queue>
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

node* max(node* root)
{
	if(root==NULL)
	return NULL;
	
	node* temp=root;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp;
}
node* inorderpredecessor(node* root, int x)
{
	if(root==NULL)
	return NULL;
	
	node* temp=search(root,x);
	
	if(temp->left!=NULL)
	{
		return max(temp->left);
	}
	else if(temp->left==NULL)
	{
		node* p=root;
		node* store;
		while(p->data!=x)
		{
			if(x>p->data)
			{
				store=p;
				p=p->right;	
			}
			else
			{
				p=p->left;
			}
		}
		return store;
	}
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
	
	node* temp=inorderpredecessor(root,46);
	cout<<temp->data;
	return 0;
}
