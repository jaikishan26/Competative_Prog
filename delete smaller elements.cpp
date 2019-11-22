#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void deletesmall(int a[], int n,int k)
{
	stack<int> s;
	s.push(a[0]);
	int count=0;
	for(int i=1;i<n;i++)
	{
		while(!s.empty()&& a[i]>s.top()&&count<k)
		{
			count++;
			s.pop();
		}
		s.push(a[i]);
	}
	int m=s.size();
	vector<int> vec(m,0);
	while(!s.empty())
	{
		vec[--m]=s.top();
		s.pop();
	}
	for(int j=0;j<vec.size();j++)
	{
		cout<<vec[j]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	stack<int> s;
	deletesmall(a,n,k);
	return 0;
	
}

