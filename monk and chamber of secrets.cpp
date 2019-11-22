#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	int n,x;
	cin>>n>>x;
	queue<int> q;
	vector<int> vec;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		q.push(a[i]);		
	}
	int c[x];
	for(int i=0;i<x;i++)
	{
		int max=0;
		int index=0;
		int p=q.size();
		int w=index;
		for(int j=0;j<x;j++)
		{
		
			int x;
			x=q.front();
			q.pop();
			if(x>max)
			{
				max=x;
				index=j;
			}
			vec.push_back(x);
			if(q.size()==0)
			{
				break;
			}
		}
		if(w>index)
		c[i]=index+1;
		else c[i]=index+2;
		int m=vec.size();
		int count=0;
		for(int k=m-1;k<=0;k--)
		{
			vec[k]==max;
			count++;
		}
		for(int k=m-1;k<=0;k--)
		{
		
			if(vec[k]==max && count>1)
			q.push(vec[k]-1);
			else if(vec[k]==max && count==1)
			continue;
			else if(vec[k]!=max)
			{
				if(vec[k]==0)
				q.push(0);
				else
				q.push(vec[k]-1);
			}
			if(vec[k]==max)
			count--;
		}
		vec.clear();
	}
	for(int i=0;i<x;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
