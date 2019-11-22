#include<iostream>
using namespace std;
int ancestor(int i, int parent[], int color[])
{
	int x=parent[i];
	while(color[i]!=color[x] && x!=0)
	{
		x=parent[x];
	}
	if(color[i]==color[x]) return x;
	return -1;
}

int main()
{
	int n,c;
	cin>>n>>c;
	int parent[n+1];
	parent[1]=0;
	int color[n+1];
	//color[0]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>parent[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>color[i];
	}
	cout<<-1<<" ";
	for(int i=2;i<=n;i++)
	{
		
		int ans=ancestor(i,parent,color);
		cout<<ans<<" ";
	}
	return 0;
}
