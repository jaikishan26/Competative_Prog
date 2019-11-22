#include<iostream>
using namespace std;
void NGE(int a[], int n)
{
	stack <int> g;
	g.push(a[0]);
	for(int i=0;i<n;i++)
	{
		int next=a[i];
		if(g.empty()==false)
		{
			int element=g.top();
			g.pop();
			
			while(next>element)
			{
				cout<<element<<"-->"<<next<<endl;
				if(g.empty()==true)
				{
					break;
				}
				element=g.top();
				g.pop();
			}
			
			if(element>next)
			{
				g.push(element);
			}
		}
		g.push(next);
	}
	
	while(g.empty()==false)
	{
		cout<<g.top()<<"-->"<<-1<<end;
		g.pop();
	}
}

int main()
{
	stack<int> g;
	int n;
	cin>>n;
	int a[n];
}
