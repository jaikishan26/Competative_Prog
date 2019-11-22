#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

string LCS(string s1, string s2)
{
	int l1= s1.length();
	int l2 = s2.length();
	int a[l1+1][l2+1];
	for(int i=0;i<l1+1;i++)
	{
		a[i][0]=0;
	}
	for(int i=0;i<l2+1;i++)
	{
		a[0][i]=0;
	}
	
	for(int i=1;i<l1+1;i++)
	{
		for(int j=1;j<l2+1;j++)
		{
			if(s1[i]==s2[j])
			{
				a[i][j]=a[i-1][j-1] + 1;
			}
			else
			{
				a[i][j]= max(a[i-1][j], a[i][j-1]);
			}
		}
	}
	string s;
	
	int maxlength = a[l1][l2];
	
	int i,j;
	i=l1;
	j=l2;
	while( i>0 && j>0)
	{
		if(a[i][j]==(a[i-1][j]||a[i][j-1]))
		{
			j=j-1;
		}
		else
		{
			s.push_back(s1[i]);
			j=j-1;
			i=i-1;
		}
	}
	cout<<maxlength<<endl;
	return s;
	
}
int main()
{
	string s1 = " acbcf";
	string s2 = " abcdaf";
	cout<<LCS(s1, s2); 
}
