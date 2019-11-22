#include<bits/stdc++.h>
using namespace std;
float dis(int a, int b, int c, int d)
{
	return sqrt(pow(d-b,2)+pow(c-a,2));
}
int main()
{
	float speed;
	cin>>speed;
	int x;
	cin>>x;
	int a[2][x];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<x;j++)
		{
			cin>>a[i][j];
		}
	}
	float ans=0;
	for(int i=0;i<x;i++)
	{
		for(int j=i+1;j<x;j++)
		{
			float temp = dis(a[0][i],a[1][i], a[0][j],a[1][j]);
			ans = max(temp,ans);
		}
	}
	ans = ans/speed;
	cout<<fixed<<setprecision(6)<<ans<<endl;
	return 0;
	
}
