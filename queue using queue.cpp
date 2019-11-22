#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char a[n];
	char x;
	int y;
	int b[n];
	queue<int> g;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x=='E')
		{
			cin>>y;
			g.push(y);
			cout<<g.size()<<endl;
		}
		else
		{
			if(g.size()==0)
			{
				cout<<-1<<" "<<0<<endl;
			}
			else
			{
				int temp=g.front();
				g.pop();
				cout<<temp<<" "<<g.size()<<endl;
			}
		}
	}
	return 0;
}
