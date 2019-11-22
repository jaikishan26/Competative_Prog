#include<bits/stdc++.h>
using namespace std;
int  main()
{
	string s;
	cin>>s;
	int n = s.length();
	vector<int> A(n+1,0);
	for(int i=1;i<=n;i++)
	{
		A[i]=A[i-1]^(1<<(s[i-1]-97));
	}
	for(int i=0;i<=n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		for(int j=i;j<=n;j++)
		{
			x  =A[j]^A[i-1];
			if(x==0||(x&(x-1))==0)
			{
				cout<<j<<i<<endl;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
