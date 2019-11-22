#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n = s.length();
	int sol=0;
	int a[26];
	for(int i=0;i<26;i++)
	{
		a[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		a[s[i]-'a']++;
	}
	int odd=0;
	for(int i=0;i<26;i++)
	{
		if(a[i]%2!=0)
		{
			odd++;
		}
	}
	if(odd>=2)
	{
		cout<<-1;
	}
	for(int i=0;i<n/2;i++)
	{
		if(s[i]!=s[n-i-1])
		{
			int j,k;
			for(j=i+1;s[j]!=s[n-i-1];j++)
			for(k=n-i-2;s[k]!=s[i];k--)
			//cout<<min(j-i,n-i-1-k)<<endl;
			sol+=min(j-i,n-i-1-k);
			if(j-i<(n-i-1-k))
			{
				char d = s[j];
				for(int p = j;p>i;p--)
				{
					s[p]=s[p-1];
				}
				s[i]=d;
			}
			else
			{
				char d = s[k];
				for(int p=k;p<n-i-1;p++)
				{
					s[p]=s[p+1];
				}
				s[n-i-1]=d;
			}
		}
	}
	cout<<s<<endl;
	cout<<sol;
}
