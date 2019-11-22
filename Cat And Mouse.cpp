#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int q;
	cin>>q;
	int a[q][3];
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	int x1,x2;
	for(int x=0;x<q;x++)
	{
		x1=abs(a[x][2]-a[x][0]);
		x2=abs(a[x][2]-a[x][1]);
		if(x1>x2)
		cout<<"Cat B";
		else if(x1<x2)
		cout<<"Cat A";
		else if(x1==x2)
		cout<<"Mouse C";
		cout<<endl;
	}
	return 0;
}
