#include <bits/stdc++.h>
using namespace std;
/*
int mini(vector<int> dis, bool visited[])
{
    int index, ans=INT_MAX;
    for(int i=1;i<=dis.size();i++)
    {
        if(!visited[i]&&dis[i]<=ans)
        {
            ans=dis[i];
            index=i;
        }
    }
    return index;
}
int dijkstra(vector<int> adj[], int n, int src)
{
    bool* visited = new bool[n+1];
    memset(visited,false, sizeof(visited));
    vector<int> dis(n+1,INT_MAX);
    dis[src]=0;
    for(int i=1;i<n;i++)
    {
        int u = mini(dis,visited);
        visited[u]=true;
        for(int j=0;j<adj[u].size();j++)
        {
            if(dis[u]!=INT_MAX&&dis[u]+1<dis[adj[u][j]]&&!visited[adj[u][j]])
            {
                dis[adj[u][j]]= dis[u]+1;
            }
        }
    }
    return dis[n];
}*/
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> adj[n+1];
	    for(int i=1;i<n;i++)
	    {
	        adj[i].push_back(i+1);
	        if(3*i<=n)
	        {
	            adj[i].push_back(3*i);
	        }
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            cout<<i<<" "<<adj[i][j]<<endl;
	        }
	    }
	    //int ans = dijkstra(adj,n,1);
	    //cout<<ans<<endl;
	}
	return 0;
}
