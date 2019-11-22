#include<iostream>
#include<queue>
using namespace std;
void interleave(queue<int> qq)
{
	queue<int> q1,q2,q3;
	queue<int> q=qq;
	int n=q.size();
	for(int i=0;i<n/2;i++)
	{
		q1.push(q.front());
		q.pop();
	}
	for(int i=n/2;i<n;i++)
	{
		q2.push(q.front());
		q.pop();
	}
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			q3.push(q1.front());
			q1.pop();
		}
		else
		{
			q3.push(q2.front());
			q2.pop();
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<q3.front()<<" ";
		q3.pop();
	}
	
}
int main()
{
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.push(16);
	q.push(17);
	q.push(18);
	q.push(19);
	q.push(20);
	interleave(q);
	return 0;
}

