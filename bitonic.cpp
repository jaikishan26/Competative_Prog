#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int *LIS(int a[], int n)
{
	int b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=1;
	}
	int temp;
	//cout<<b[0]<<endl;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			//temp = b[i];
			if(a[i]>a[j])
			{
				temp = b[j]+1;
				if(temp>b[i])
				{
					
					b[i] = temp;
				}
			}
		}
	}
	//sort(b, b+n);
	return b;
}

int *LISreverse(int a[], int n)
{
	int b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=1;
	}
	int temp;
	//cout<<b[0]<<endl;
	for(int i=n-2;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			//temp = b[i];
			if(a[i]>a[j])
			{
				temp = b[j]+1;
				if(temp>b[i])
				{
					
					b[i] = temp;
				}
			}
		}
	}
	//sort(b, b+n);
	return b;
}


int bitonic( int a[], int n)
{
	
	int b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=1;
	}
	int temp;
	//cout<<b[0]<<endl;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			//temp = b[i];
			if(a[i]>a[j])
			{
				temp = b[j]+1;
				if(temp>b[i])
				{
					
					b[i] = temp;
				}
			}
		}
	}
	int c[n];
	for(int i=0;i<n;i++)
	{
		c[i]=a[n-1-i];
	}
	int d[n];

	for(int i=0;i<n;i++)
	{
		d[i]=1;
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			//temp = b[i];
			if(c[i]>c[j])
			{
				temp = d[j]+1;
				if(temp>d[i])
				{
					
					d[i] = temp;
				}
			}
		}
	}
	
	


	for(int i=0;i<n;i++)
	{
		b[i]=b[i] + d[n-1-i];
	}
	sort(b, b+n);
	return b[n-1]-1;
}
 int main()
 {
 	int a[] = {1,11,2,10,4,5,2,1};
 	cout<<bitonic(a,8)<<endl;
 	return 0;
 }
