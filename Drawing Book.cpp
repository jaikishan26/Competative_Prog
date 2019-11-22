#include<iostream>
using namespace std;
int main()
{
	int n,p;
	cin>>n>>p;
	int c=0;
	if((n%2)==0)
	{
		int t=1;
		int l=n;
		int k;
		k=n/2;
		if(p<=k)
		//front se counting
		{
			for(int i=0;i<n;i++)
			{
				if(t<p)
				{
					t=t+2;
					c++;
				}
				else break;
			}
		}
		else if(p>k)
		{
			for(int i=0;i<n;i++)
			{
				if(l>p)
				{
					l=l-2;
					c++;
				}
				else break;
			}
		}
		
	}
	else
	{
		int y=n-1;
		int j=1;
		int r;
		r=n/2;
		if(p<=r)
		{
			for(int o=0;o<n;o++)
			{
				if(j<p)
				{
					j=j+2;
					c++;
				}
				else break;
			}
		}
		else if(p>r)
		{
			for(int w=0;w<n;w++)
			{
				if(y>p)
				{
					y=y-2;
					c++;
				}
				else break;
			}
		}	
	}
	cout<<c;
	return 0;
}
