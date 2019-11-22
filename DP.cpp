#include<iostream>
using namespace std;

long long int result[100002]={-1};

long long int fac(int n)
{
	if(n<=1)
	return 1;
	if(result[n]!=0)
	return result[n];
	result[n] = (n*fac(n-1));
	return result[n];
}
 int main()
 {
 	result[0]=1;
 	result[1]=1;
	 int t;
 	cin>>t;
 	int a[t];
 	int x;
 	for(int i=0;i<t;i++)
 	{
 		cin>>x;
 		a[i]=x;
 		int temp=fac(x);
	}
	for(int i=0;i<t;i++)
	{
	    cout<<result[a[i]]%1000000007<<endl;
	}
	return 0;
 }
