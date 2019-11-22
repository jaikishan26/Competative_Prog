#include<bits/stdc++.h>
using namespace std;
int check(string s)
{
	map<char,int> m;
	for(int i=0;i<s.length();i++)
	{
		m[s[i]]++;
	}
	int count=0;
	map<char,int> :: iterator i;
	for( i=m.begin();i!=m.end();i++)
	{
		if(i->second%2!=0)
		count++;
	}
	if(count<2)
	return true;
	return false;
}
int main()
{
	string s;
	cin>>s;
	int i=0;
	int j=s.length()-1;
	int n = s.length();
	int count=0;
	if(check(s))
	{
		for(int i=0;i<n/2;i++)
		{
			bool flag=false;
			for(int j=n-1-i;j>i;j--)
			{
				if(s[i]==s[j])
				{
					flag=true;
					for(int k=j+1;k<n-i;k++)
					{
						swap(s[k],s[k-1]);
						count++;
					}
					break;
				}
			}
			if(!flag)
			{
				for(int j=i;j<n/2;j++)
				{
					swap(s[j],s[j+1]);
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	else
	{
		cout<<"Impossible"<<endl;
	}
	return 0;
}
