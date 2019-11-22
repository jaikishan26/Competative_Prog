#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > low;
	priority_queue<int> high;
	int a[n];
	int x;
	int median;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a[i]=x;
	}
	
	for(int i=0;i<n;i++)
	{
		int x = a[i];
		
		if(high.size()==0|| x<high.top())
		{
			high.push(x);
			
			cout<<high.size();
		}
		else
		{
			low.push(x);
		}
		
		if((high.size()-low.size())>=2)
		{
			low.push(high.top());
			high.pop();
			
		}
	
		else if((low.size()-high.size())>=2)
		{
			high.push(low.top());
			low.pop();
		}
		cout<<"p"<<endl;
		cout<<high.size()<<" "<<low.size()<<endl;
		//rebalance(min, max);
		cout<<"p"<<endl;
		if(high.size()==low.size())
		{
			median =  (high.top() + low.top())/2;
		}
	
		else if(high.size()>low.size())
		{
			//cout<<min.top();
			median =  high.top();
		}
	
		else median =  low.top();
	//cout<<endl<<"mm"<<min.size();
	//median(min, max);
	//	cout<<number<<endl;
	cout<<median<<endl;
	}
	return 0;
}
