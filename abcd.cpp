#include<iostream>
#include<cmath>
using namespace std;
#define rr long long int
int partition(long long int a[], int start ,int end)
{
	int pindex= start;
	rr pivot=a[end];
	for(int i=start;i<end;i++)
	{
		if(abs(a[i])<=abs(a[end]))
		{
			swap(a[i],a[pindex]);
			pindex++;
		}
		
	}
	swap(a[end], a[pindex]);
	return pindex;
}

void qsort(long long int a[],int start, int end)
{
	if(start<end)
	{
		int pindex= partition(a,start,end);
		qsort(a,start, pindex-1);
		qsort(a,pindex+1,end);
	}
}

int main()
{
	int n;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	qsort(a,0,n-1);
	for(int j=0;j<n;j++)
	{
		cout<<a[j]<<" ";
	}
	return 0;
}
