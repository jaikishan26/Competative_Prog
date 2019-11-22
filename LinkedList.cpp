#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};
node* head;
node* newnode(int x)
{
	node* temp = new node();
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void insert(int x, int n)
{
	node* temp = newnode(x);
	node* dummy=head;
	if(n==1)
	{
		temp->next=dummy;
		head=temp;
		cout<<"inserted"<<endl;
		return;
	}
		for(int i=0;i<(n-2);i++)
		{
			dummy=dummy->next;
		}
		temp->next=dummy->next;
		dummy->next=temp;
}
void deleten(int n)
{
			node* temp=head;

	if(n==1)
	{
		head=temp->next;
		free(temp);
		return;
	}
	else
	{
		while(n-2>0&&temp->next!=NULL)
		{
			temp=temp->next;
			n--;
		}
		node* p = temp->next;
		temp->next=p->next;
		free(p);
		return;
	}
}

void reverse()
{
	node* current;
	node* next;
	node* pre;
	pre=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=pre;
		pre=current;
		current=next;
	}
	head=pre;
}

void reverserecursion(node* temp)
{
	if(temp->next==NULL)
	{
		head=temp;
		return;
	}
	reverserecursion(temp->next);
	node* q = temp->next;
	q->next=temp;
	//temp->next=NULL;
}

void print()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	head=NULL;
	insert(1,1);
	insert(2,2);
	insert(3,3);
	insert(4,4);
	insert(5,4);
	print();
	deleten(1);
	deleten(3);
	print();
	node* r=head;
	reverserecursion(r);
	print();
	return 0;
	
}
