#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m;
		cin>>n>>m;
		int a[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		int p=abs(n-m);
		sort(a,a+n);
		int min,max;
		min=0;
		max=0;
		for(int x=0;x<p;x++)
		{
			min+=a[x];
			max+=a[n-1-x];
		}
		int y=0;
		y=max-min;
		cout<<y<<endl;
	}	
	return 0;
	
}
