#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > A(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>A[i][j];
		}
	}
	int y = n/3;
	vector<int> x;
	int k=0;
	int a=0;
	int b=a+y;
	int c=b+y;
	while(k<y)
	{
		for(int i=0;i<m;i++)
		{
			x.push_back(A[a][i]);
			x.push_back(A[b][i]);
			x.push_back(A[c][i]);
		}
		a++;
		b++;
		c++;
		k++;
	}
	for(int i=0;i<x.size();i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
	vector<string> sol;
	for(int i=0;i<x.size();i++)
	{
		string s="";
		for(int j=7;j>=0;j--)
		{
			if(x[i]&(1<<j))
			{
				s+="1";
			}
			else
			{
				s+="0";
			}
		}
		sol.push_back(s);
	}
	for(int i=0;i<sol.size();i++)
	{
		cout<<sol[i]<<" ";
	}
	return 0;
}
