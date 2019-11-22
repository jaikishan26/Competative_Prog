#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> a(m);
	vector<int> b(m);
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	vector<priority_queue<int> > A(n+1);
	int count=0;
	for(int i=0;i<m;i++)
	{
		if(a[i]>b[i])
		{
			A[a[i]].push(b[i]);
		}
		else
		{
			A[b[i]].push(a[i]);
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(A[i].empty())
		{
			q.push(i);
			count++;
		}
		else
		{
			while(!q.empty()&&!A[i].empty()&&q.front()<=A[i].top()&&q.back()>=A[i].top())
			{
				if(q.front()>=A[i].top())
				{
					A[i].pop();
				}
				q.pop();
				count+=q.size();
			}
			q.push(i);
			count++;
		}
	}
	int s = q.size();
	if(s>0)
	{
		count+=(s*(s-1))/2;
	}
	cout<<count<<endl;
	return 0;
}
