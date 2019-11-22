#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x;
	int y;
};


bool compareX(point a, point b)
{
	return a.x<b.x;
}
bool compareY(point a, point b)
{
	return a.y<b.y;
}
double dist(point a, point b)
{
	double p =  (float)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
	return p;
}
double bruteforce(point A[], int n)
{
	double mini= FLT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			double d = dist(A[i],A[j]);
			if(d<mini)
			{
				mini = d;
			}
		}
	}
	return mini;
}
double stripmin(point strip[], int n, float d)
{
	double ans=d;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n&&(strip[j].y-strip[i].y<d);j++)
		{
			float z = dist(strip[i],strip[j]);
			if(z<ans)
			{
				ans= z;
			}
		}
	}
	return ans;
}

double minimumdis(point A[], int n)
{
	if(n<=3)
	{
		return bruteforce(A,n);
	}
	int mid = n/2;
	point midpoint=A[mid];
	double lm=minimumdis(A,mid);
	double rm=minimumdis(A+mid,n-mid);
	double d = min(lm,rm);
	point strip[n];
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(abs(A[i].x-midpoint.x)<d)
		{
			strip[j++]=A[i];
		}
	}
	sort(strip,strip+j,compareY);
	return min(d,stripmin(strip,j,d));
}

int main()
{
	int n;
	cin>>n;
	point A[n];
	point p;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		p.x=x;
		p.y=y;
		A[i]=p;
	}
	sort(A,A+n,compareX);
	double d = minimumdis(A,n);
	cout<<fixed<<setprecision(6)<<d;
	d = round(d*1000000)/1000000;
	//cout<<d;
	return 0;
}
