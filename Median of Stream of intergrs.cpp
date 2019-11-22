#include<iostream>
#include<stack>
#include<queue>
using namespace std;

priority_queue<int> high;
priority_queue<int, vector<int>, greater<int> > low;

int getmedian(int x)
{
	//cout<<"hello"<<endl;
	if(high.size()==0 || x<high.top())
	{
		high.push(x);
	}
	else
	{
		low.push(x);
	}
	int a = high.size();
	int b = low.size();
	if(a-b>1)
	{
		low.push(high.top());
		high.pop();
	}
	else if(b-a>1)
	{
		high.push(low.top());
		low.pop();
	}
	
	int m = high.size();
	int n = low.size();
	if(m==n)
	{
		return (high.top()+low.top())/2;
	}
	else if(m>n)
	{
		return high.top();
	}
	else
	return low.top();
}

int main()
{
	
	int n= 5;
	//high.clear();
	while(!high.empty())
	{
	    high.pop();
	}
	while(!low.empty())
	{
	    low.pop();
	}
	//int temp = 0;
	for(int i=0;i<n;i++)
	{
		int temp = 0;
		cin>>temp;
		cout<<getmedian(temp)<<endl;
	}
	return 0;
}
