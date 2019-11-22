#include<iostream>
using namespace std;
#define rr long long int

void merge(long long int left[], long long int right[], long long int arr[], long long int nl, long long int nr)
{
	long long int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<nl && j<nr)
	{
		if(left[i]>=right[j])
		{
			arr[k++]=left[i++];
		}
		else
		{
			arr[k++]=right[j++];
		}
	}
	while(i<nl)
	{
		arr[k++]=left[i++];
	}
	while(j<nr)
	{
		arr[k++]=right[j++];
	}
}

void merge_sort(long long int arr[],long long int n)
{
	long long int mid=(n/2);
	long long int left[mid];
	long long int right[n-mid];
	if(n<2)
	return;
	for(long long int i=0;i<mid;i++)
	{
		left[i]=arr[i];
	}
	for(long long int j=mid;j<n;j++)
	{
		right[j-mid]=arr[j];
	}
	merge_sort(left,mid);
	merge_sort(right,n-mid);
	merge(left,right,arr,mid,n-mid);
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		rr n;
		cin>>n;
		rr a[n];
		for(rr j=0;j<n;j++)
		{
			cin>>a[j];
		}
		merge_sort(a,n);
		for(rr p=0;p<n;p++)
		{
			cout<<a[p]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
