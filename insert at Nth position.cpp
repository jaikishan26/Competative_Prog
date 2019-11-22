#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
struct node* head;
void insert(int x, int n)
{
	node* temp= new node();
	temp->data=x;
	temp->next=NULL;
	if(n==1)
	{
		temp->next=head;
		head=temp;
		return ;
	}
	node* temp1=head;
	for(int i=0;i<n-2;i++)
	{
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}

void display()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void deletelink(int n)
{
	node* temp=head;
	if(n==1)
	{
		//temp=temp->next;
		head=temp->next;
		//temp->next=NULL;
		delete(temp);
		return;
	}
	
	for(int i=0;i<n-2;i++)
	{
		temp=temp->next;
	}
	node* temp1=temp->next;
	temp->next=temp1->next;
	temp1->next=NULL;
}

void reverse()
{
	node* current=head;
	node* prev=NULL;
	node *next;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}

void reverseRec(node* p)
{
	if(p->next==NULL)
	{
		head=p;
		return;
	}
	reverseRec(p->next);
	node* q=p->next;
	q->next=p;
	p->next=NULL;
}
int main()
{
	head=NULL;
	insert(4,1);
	insert(9,2);
	insert(11,1);
	insert(21,2);
	display();
	deletelink(1);
	display();
//	reverse();
	reverseRec(head);
	display();
	return 0;
}
