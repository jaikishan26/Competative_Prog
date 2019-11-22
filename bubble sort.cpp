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
	int count=0;
	int temp;
	for(int j=0;j<(n-1);j++)
	{
		for(int k=0;k<(n-j-1);k++)
		{
			if(a[k]>a[k+1])
			{
				temp=a[k+1];
				a[k+1]=a[k];
				a[k]=temp;
				count++;
			}
			else if(a[k]==a[k+1])
			continue;
		}
	}
	cout<<count;
	return 0;
}
