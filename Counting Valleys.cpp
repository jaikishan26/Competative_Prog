#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	int v,m,c;
	c=0;
	m=0;
	v=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='U')
		{
			c++;
			if(c==0)
			v++;
		}
		else if(str[i]=='D')
		{
			c--;
			if(c==0)
			m++;
		}
	}
	cout<<v;
	return 0;
}
