#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==k)
		{
			a[i]=0;
		}
		sum+=a[i];
	}
	int c;
	cin>>c;
	int temp;
	temp=sum/2;
	if(c==temp)
	{
		cout<<"Bon Appetit";
	}
	else cout<<abs(c-temp);
	return 0;
	
	
}
