#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

void insert(int x, node* head)
{
	node* temp =new node();
	node* temp1=head;
	temp->data=x;
	temp->next=NULL;
	while(temp1!=NULL)
	temp1=temp1->next;
	temp1->next=temp;
	//head=temp;
	//return head;
}

void print(node* head)
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
	node* head=NULL;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		//head = insert(x,head);
		insert(x,head);
		print(head);
	}
	return 0;
}


