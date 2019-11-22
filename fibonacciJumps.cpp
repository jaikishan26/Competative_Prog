#include<bits/stdc++.h>
using namespace std;
vector<int> fib;
set<int> s;
int ans;
void jumps(vector<int> &A, int n, int jump)
{
    if(n==-1)
    {
        ans = min(ans,jump);
        return;
    }
    if(s.find(n+1)!=s.end())
    {
        jumps(A,-1,jump+1);
    }
    else
    {
        for(int i=n-1;i>=0;i--)
        {
            if(A[i]==1)
            {
                int x = n-i;
                if(s.find(x)!=s.end())
                {
                    jumps(A,i,jump+1);
                }
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    s.clear();
    s.insert(0);
    s.insert(1);
    s.insert(2);
    int a=1;
    int b=2;
    ans=INT_MAX;
    while(1)
    {
        int x = a+b;
        a=b;
        b=x;
        if(x>(n+1))
        break;
        //fib.push_back(x);
        s.insert(x);
    }
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(s.find(i+1)!=s.end())
        {
            dp[i]=1;
        }
        else
        {
            int y=INT_MAX;
            for(int j=i-1;j>=0;j--)
            {
                if(A[j]==1)
                {
                    int x = i-j;
                    if(s.find(x)!=s.end())
                    {
                        if(dp[j]==INT_MAX)
                        continue;
                        else
                        {
                            y = min(y,1+dp[j]);
                        }
                    }
                }
            }
            dp[i]=y;
        }
    }
    if(s.find(n+1)!=s.end())
    {
        cout<<1<<endl;
    }
    else
    {
       // jumps(A,n,0);
        cout<<dp[n]<<endl;
    }
    return 0;
    
}
