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
	int b[n];
	for(int i=0;i<n;i++)
	{
		int temp=a[i];
		int j=i;
		while(j>0 && temp<a[j-1])
		{
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=temp;
		b[i]=j+1;
	}
	for(int p=0;p<n;p++)
	{
		cout<<b[p]<<" ";
	}
	return 0;
}
