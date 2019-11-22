#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define INTMAX 1000000
#define INTMIN -1000000

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
	temp->left=temp->right=NULL;
	return temp;
}

node* insert( node* root, int x)
{
	if(root==NULL)
	{
		root = newnode(x);
		return root;
	}
	if(x<=root->data)
	{
		root->left= insert(root->left, x);
		return root;
	}
	else
	{
		root->right= insert(root->right,x);
		return root;
	}
	
}

node* insertiterative(node* root, int x)
{
	node* temp = newnode(x);
	if(root==NULL)
	return temp;
	node* parent;
	node* current;
	current = root;
	parent=NULL;
	while(current!=NULL)
	{
		parent=current;
		if(x<=current->data)
		{
			current=current->left;
		}
		else
		current=current->right;
	}
	
	if(x<=parent->data)
	{
		parent->left=temp;
	}
	else
	parent->right=temp;
	
	return root;
}

////////////////////// search element

node* search(node* root, int x)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==x)
	{
		return root;
	}
	else if(x<root->data)
	{
		return search(root->left,x);
	}
	else
	{
		return search(root->right,x);
	}
}

bool isSmaller(node* root, int x)
{
	if(root==NULL)
	return true;
	if(root->data<=x && isSmaller(root->left,x) && isSmaller(root->right,x))
	return true;
	else return false;
}

bool isGreater(node* root, int x)
{
	if(root==NULL)
	return true;
	if(root->data>x && isGreater(root->left,x) && isGreater(root->right,x))
	return true;
	else return false;
}

bool checkBST(node* root) // O(n^2)
{
	if(root==NULL)
	return true;
	if(isSmaller(root->left,root->data) && isGreater(root->right,root->data) && checkBST(root->left) && checkBST(root->right))
	return true;
	else return false;
}

bool CheckBst(node* root, int max, int min) // O(n)
{
	if(root==NULL)
	return true;
	if(root->data>min && root->data<max && CheckBst(root->left,root->data, min) && CheckBst(root->right,max, root->data))
	return true;
	else return false;
}

//    inorder traversal    /////////////////////////

void inorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data;
	inorder(root->left);
	inorder(root->right);
}

// level order traversal/////////////////////////

void levelorder(node* root)
{
	if(root==NULL)
	return;
	queue <node*> q;
	q.push(root);
	while(q.size()!=0)
	{
		node* current=q.front();
	//	temp=q.front();
		if(current->left!=NULL) q.push(current->left);
		if(current->right!=NULL) q.push(current->right);
		cout<<current->data;
		q.pop();
		
	}
}

node* findmin(node* root)
{
	node* temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

node* deletenode(node* root, int x)
{
	
	if(root==NULL)
	{
		return NULL;
	}
	else if(x>root->data)
	{
		root->right=deletenode(root->right,x);
	}
	else if(x<root->data)
	{
		root->left=deletenode(root->left,x);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete(root);
			root=NULL;
			return root;
		}
		
		else if(root->right==NULL)
		{
			node* temp=root;
			root=root->left;
			delete(temp);
			return root;
		}
		
		else if(root->left==NULL)
		{
			node* temp=root;
			root=root->right;
			delete(temp);
			return root;
		}

		else
		{
			node* temp= findmin(root->right);
			root->data=temp->data;
			root->right=deletenode(root->right,temp->data);
			return root;
		}
	}
}
///////////// Root to leaf sum binary tree   //////////////////////////

bool roottoleaf(node* root, int sum, stack<int> list)
{
	if(root==NULL)
	{
		return false;
	}
	
	else if(root->left==NULL && root->right==NULL)
	{
		if(root->data==sum)
		{
			list.push(root->data);
			return true;
		}
		else return false;
	}
	
	if(roottoleaf(root->left, sum-root->data, list))
	{
		list.push(root->data);
		return true;
	}
	if(roottoleaf(root->right, sum-root->data, list))
	{
		list.push(root->data);
		return true;
	}
	return false;
}


int main()
{
	node* root;
	int max=100000;
	int min=-100000;
	root=NULL;
	root=insert(root,5);
	root=insert(root,11);
	root=insert(root,56);
	root=insert(root,4);
	root=insert(root,1);
//	root=insert(root,3);
	root=insert(root,8);
	node* temp=search(root, 56);
	//cout<<temp->data;
	cout<<CheckBst(root, max, min);
	cout<<endl;
	cout<<checkBST(root)<<endl;
	inorder(root);
	cout<<endl;
	//levelorder(root);
	cout<<endl;
	root=deletenode(root,56);
	levelorder(root);
	cout<<endl;
	stack<int> list;
	cout<<roottoleaf(root,24,list)<<endl<<list.size();
	while(list.size()!=0)
	{
		cout<<list.top()<<" ";
		list.pop();
	}
	return 0;
}
