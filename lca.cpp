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

node* lcaBST(node* root, int a, int b)
{
	if(root==NULL)
	return NULL;
	
	if(root->data>max(a,b))
	{
		return lcaBST(root->left,a,b);
	}
	else if(root->data< min(a,b))
	{
		return lcaBST(root->right,a,b);
	}
	else return root;
}

node* lcaBT(node* root, int a , int b)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	if(root->data==a || root->data==b)
	{
		return root;
	}
	node* left = lcaBT(root->left,a,b);
	node* right = lcaBT(root->right,a,b);
	
	if(left!=NULL && right!=NULL)
	 return root;
	
	if(left==NULL && right==NULL)
	return NULL;
	
	return left!=NULL? left:right;

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
	
	//preorderiterative(root);
	//cout<<endl;
	//inorderiterative(root);
	//cout<<endl;
	//postorderiterative(root);
	//cout<<endl;
	
	//LEVELBYLEVEL(root);
	//levelBYlevel(root);
	//levelorderreverse(root);
	
	node* a=lcaBST(root,50,90);
	cout<<a->data<<endl;
	a=lcaBST(root,30,46);
	cout<<a->data<<endl;
	return 0;
}
