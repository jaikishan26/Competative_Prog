#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int par[], int color[],int main[],int u, int p, int &cyclenumber)
{
	color[u]=1;
	par[u]=p;
	for(int j=0;j<adj[u].size();j++)
	{
		if(color[adj[u][j]]==1)
		{
			cout<<"*"<<endl;
				int cur=p;
				cyclenumber++;
				main[cur]=cyclenumber;
				while(cur!=u)
				{
					cur=par[cur];
					main[cur]=cyclenumber;
				}
		}
		else if(color[adj[u][j]]==0)
		{
			dfs(adj,par,color,main,adj[u][j],u,cyclenumber);
		}
	}
	color[u]=2;
}

void printcycles(int main[], int v, int &cyclenumber)
{
	vector<int> print[v];
	for(int i=0;i<v;i++)
	{
		if(main[i]!=0)
		{
			print[cyclenumber].push_back(i);
		}
	}
	for(int i=1;i<=cyclenumber;i++)
	{
		for(int j=0;j<print[i].size();j++)
		{
			cout<<print[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int v;
	cin>>v;
	int e;
	cin>>e;
	vector<int> adj[v];
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
	}
	int cyclenumber=0;
	int *color = new int[v];
	memset(color, 0,sizeof(color));
	int *par = new int[v];
	int p=-1;
	int *main = new int[v];
	memset(main,0,sizeof(main));
	dfs(adj,par,color,main,0,p,cyclenumber);
	cout<<cyclenumber<<endl;
	printcycles(main,v,cyclenumber);
	return 0;
}
