#include<bits/stdc++.h>
using namespace std;
int main()
{
	string p,t;
	cin>>p>>t;
	string str = p+"#"+t;
	cout<<str;
	int l=str.length();
	int a[l];
	a[0]=0;
	int j=0;
	int count=0;
	for(int i=1;i<l;i++)
	{
		//j=a[i-1];
		while(j>0&&str[i]!=str[j])
		{
			j=a[i-1];
		}
		if(str[i]==str[j])
		{
			j++;
		}
		a[i]=j;
		if(a[i]==p.length())
		count++;
	}
	cout<<count;
	return 0;
}
