#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int c=0;
	for(int j=0;j<(n-1);j++)
	{
		for(int k=(j+1);k<n;k++)
		{
			int p=a[j]-a[k];
			if(p<=1)
			c++;
			else continue;
		}
	}
	cout<<c;
	return 0;
}
