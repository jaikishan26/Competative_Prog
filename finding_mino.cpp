#include<bits/stdc++.h>
using namespace std; 

double func(double x)
{
	return 2*x*x - 12*x + 7;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		double l,r;
		cin>>l>>r;
		for(int i=0;i<201;i++)
		{
			double l1 = (2*l+r)/3;
			double l2 = (2*r+l)/3;
			if(func(l1)>func(l2))
			{
				l=l1;	
			}	
			else r= l2;
		}
		cout<<func(l)<<endl;
	}
	return 0;
	
}
