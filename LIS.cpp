#include<iostream>
#include<algorithm>
using namespace std;

int LIS(int a[], int n)
{
	int b[n]={1,1,1,1,1,1,1};
	int temp;
	cout<<b[0]<<endl;
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
		cout<<b[i]<<endl;
	}
	sort(b, b+n);
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	return b[n-1];
}
int main()
{
	int a[] = { 3, 4, -1, 0, 6, 2, 3};

	cout<<LIS(a, 7);
	return 0;
}
