#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n = s.length();
	int dp[5]={0};
	bool a=false;
	bool e=false,I=false,o=false,u=false;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			dp[0]++;
			a=1;
		}
		if(s[i]=='e'&&a==true)
		{
			dp[1]=max(dp[0]+1,dp[1]+1);
			e=true;
		}
		if(s[i]=='i'&&e==true)
		{
			dp[2]=max(dp[2]+1,dp[1]+1);
			I=true;
		}
		if(s[i]=='o'&&I==true)
		{
			dp[3]=max(dp[2]+1,dp[3]+3);
			o=true;
		}
		if(s[i]=='u'&&o==true)
		{
			dp[4]=max(dp[4]+1,dp[3]+1);
			u=true;
		}
	}
	if(a&&e&&I&&o&&u)
	{
		cout<<dp[4];
	}
	else cout<<0;
}
