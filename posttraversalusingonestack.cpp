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

void postusingonestack(node* root)
{
	if(root==NULL)
	{
		return ;
	}
	stack<node*> s;
//	s.push(root);
	node* current=root;
	while(current!=NULL || !s.empty())
	{
		if(current!=NULL)
		{
			s.push(current);
			current=current->left;			
		}
		else
		{
			node* x=s.top();
			node* temp=x->right;
			if(temp==NULL)
			{
				s.pop();
				cout<<x->data<<" ";
				node* p=s.top();
				while(!s.empty() && x==p->right)
				{
					cout<<p->data<<" ";
					s.pop();
				}
			}
			else
			{
				current=temp;
			}
			
		}
	}
}
