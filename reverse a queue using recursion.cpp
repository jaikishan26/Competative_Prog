#include<iostream>
#include<queue>
using namespace std;

queue<int> reverse(queue<int> q, int n, const int p)
{
	if(q.size()==0)
	return q;
	int x= q.front();
	q.pop();
	q=reverse(q,q.size(),p);
	q.push(x);
	
	return q;
	 
	//if(q.size()==p)
	//{
	//for(int i=0;i<p;i++)
	//{
//			cout<<q.front()<<" ";
//			q.pop();
//	}
//	}
	
	
}

int main()
{
	int n;
	cin>>n;
	const int p=n;
	queue<int> q;
	int x=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		q.push(x);
	}
	queue<int> qq;
	qq=reverse(q,n,p);
	
	for(int i=0;i<p;i++)
	{
		cout<<qq.front()<<" ";
		qq.pop();
	}

	return 0;
}
