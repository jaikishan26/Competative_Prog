#include<iostream>
using namespace std;

//void swap(int a, int b)
//{
//	int temp =b;
//	b=a;
//	a = temp;
//}

void maxheapify(int a[], int n, int i)
{
	int left = 2*i+1;
	int right = 2*i+2;
	int greatest = i;
	if(left<n && a[greatest]<a[left])
	{
		greatest = left;
	}
	if(right<n && a[greatest]<a[right])
	{
		greatest = right;
	}
	if(greatest!=i)
	{
		swap(a[i], a[greatest]);
		maxheapify(a , n, greatest);
	}
	
}

void heapsort( int a[], int n)
{
	for(int i = n/2 - 1; i>=0; i--)
 	{
		maxheapify(a, n , i);// building heap
	}
	
	for(int i=n-1;i>=0;i--)
	{
		swap(a[0], a[i]);
		maxheapify(a, i, 0);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	heapsort(a, n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
