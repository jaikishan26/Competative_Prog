#include<bits/stdc++.h>
using namespace std;
struct trie
{
	int value;
	trie* A[2];
};
trie* newnode()
{
	trie* temp = new trie;
	temp->A[0]=temp->A[1]=NULL;
	temp->value=0;
	return temp;
}
void insert(trie* root, int prexor)
{
//	if(root==NULL)
//	root=newnode();
	trie* temp = root;
	for(int i=31;i>=0;i--)
	{
		bool p = (prexor&(1<<i));
		if(temp->A[p]==NULL)
		{
			temp->A[p]=newnode();
			temp = temp->A[p];
		}
		else
		{
			temp=temp->A[p];
		}
	}
	temp->value=prexor;
}
int query(trie* root, int prexor)
{
	//if(root==NULL)
//	return 0;
	trie* temp=root;
	for(int i=31;i>=0;i--)
	{
		bool p = (prexor&(1<<i));
		if(temp->A[1-p]!=NULL)
		{
			temp=temp->A[1-p];	
		}	
		else if(temp->A[p]!=NULL)
		{
			temp = temp->A[p];
		}
	}
	return prexor^(temp->value);
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int result = INT_MIN;
	int prexor=0;
	trie* root=newnode();
	insert(root,0);
	cout<<query(root,0);
	for(int i=0;i<n;i++)
	{
		prexor = prexor^v[i];
		insert(root,prexor);
		result = max(result,query(root,prexor));
		cout<<result<<endl;
	}
	cout<<result<<endl;
	return 0;
}
