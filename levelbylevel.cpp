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

void levelbylevel(node* root)
{
	if(root==NULL)
	return ;
	queue<node*> q;
	queue<node*> out;
	node* del = NULL;
	node* temp=root;
	q.push(root);
	q.push(del);
	while(!q.empty())
	{
		node* current = q.front();
		q.pop();
		if(q.empty())
		break;
		if(current==NULL)
		{
			q.push(del);
			cout<<endl;
		}
		else
		{
			cout<<current->data<<" ";

			if(current->left!=NULL)
			{
				q.push(current->left);
			}
			if(current->right!=NULL)
			{
				q.push(current->right);
			}
		}
	}
}

void LEVELBYLEVEL(node* root)
{
	if(root==NULL)
	return;
	queue<node*> q1;
	queue<node*> q2;
	//node* temp=root;
	q1.push(root);
	while(!q1.empty() || !q2.empty())
	{
		while(!q1.empty())
		{
			node* temp=q1.front();
			q1.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
			{
				q2.push(temp->left);
			}
			if(temp->right!=NULL)
			{
				q2.push(temp->right);
			}
		}
		cout<<endl;
		
		while(!q2.empty())
		{
			node* t=q2.front();
			q2.pop();
			cout<<t->data<<" ";
			if(t->left!=NULL)
			{
				q1.push(t->left);
			}
			if(t->right!=NULL)
			{
				q1.push(t->right);
			}
		}
		cout<<endl;
	}
}

void levelBYlevel(node* root)
{
	if(root==NULL)
	return;
	queue<node*> q;
	int levelcount=1, currentcount=0;
	//de* current;
	//current=root;
	q.push(root);
	while(!q.empty())
	{
		node* current=q.front();
		q.pop();
		//levelcount--;
		if(current->left!=NULL)
		{
			q.push(current->left);
			currentcount++;
		}
		if(current->right!=NULL)
		{
			q.push(current->right);
			currentcount++;
		}
		cout<<current->data<<" ";
		levelcount--;
		if(levelcount==0)
		{
			levelcount=currentcount;
			currentcount=0;
			cout<<endl;
		}
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
	
	//preorderiterative(root);
	//cout<<endl;
	//inorderiterative(root);
	//cout<<endl;
	//postorderiterative(root);
	//cout<<endl;
	
	//LEVELBYLEVEL(root);
	levelBYlevel(root);
	return 0;
}

