#include <bits/stdc++.h>
using namespace std;

void print(int &count,vector<int> &A,vector<vector<bool> > &dp, int n, int sum,vector<int> &p)
{
    if(n<=0)
    return;
    if(n==1&&sum!=0&&dp[n][sum])
    {
        p.push_back(A[n-1]);
        count++;
        return;
    }
    if(sum==0)
    {
        count++;
        return;
    }
    if(dp[n-1][sum])
    {
        vector<int> b=p;
        print(count,A,dp,n-1,sum,b);
    }
    if(sum>=A[n-1]&&dp[n-1][sum-A[n-1]])
    {
        p.push_back(A[n-1]);
        print(count,A,dp,n-1,sum-A[n-1],p);
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int count=0;
	    int n;
	    cin>>n;
	    vector<int> A(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>A[i];
	    }
	    sort(A.begin(),A.end());
	    int sum;
	    cin>>sum;
	    vector<vector<bool> > dp(n+1,vector<bool>(sum+1));
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0] = true;
	    }
	    for(int i=1;i<=sum;i++)
	    {
	        dp[0][i]=false;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(A[i-1]<=j)
	            {
	                dp[i][j] = dp[i-1][j]||dp[i-1][j-A[i-1]];
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    if(dp[n][sum]==false)
	    cout<<0<<endl;
	    else
	    {
	        vector<int> p;
	        print(count,A,dp,n,sum,p);
	        cout<<count<<endl;
	    }
	}
	return 0;
}
