#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;;
	string str[n];
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	
	int a[26]={0};
	string res;
	int maximum=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<26;j++)
		{
			a[j]=0;
		}
		for(int k=0;k<n;k++)
		{
			a[str[k][i]-'a']++;
			maximum=max(maximum, a[str[k][i]-'a']);
		}
		for(int p=0;p<26;p++)
		{
			if(a[p]==maximum)
			{
				res += 'a' + p;
				break;
			}
		}
	}
	cout<<res;
	return 0;
}

