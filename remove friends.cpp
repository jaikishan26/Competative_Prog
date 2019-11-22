#include<iostream>
#include<stack>
using namespace std;
 int main()
 {
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	
 	int t;
 	cin>>t;
 	for(int i=0;i<t;i++)
 	{
 		int n,k;
		cin>>n>>k;
		stack<int> s;
		stack<int> ss;
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(s.empty())
			{
				s.push(temp);
			}	
			
			else
			{
				while(temp>s.top() && k>0)
				{
					//cout<<s.top();
					s.pop();
					k--;
					if(s.empty()) break;
				}
			}
			
			s.push(temp);
		}
		cout<<endl;
		cout<<s.size();
		while(k>0)
		{
			s.pop();
			k--;
		}	
		
		while(s.size()!=0)
		{
			ss.push(s.top());
			s.pop();
			cout<<ss.top();
		}
		
		while(ss.size()!=0)
		{
			cout<<ss.top()<<" ";
			ss.pop();
		}
		cout<<endl;
	}
	return 0;
 }
