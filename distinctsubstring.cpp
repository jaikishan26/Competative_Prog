#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int j=0;int i=0;
	int l=0;
	int result=INT_MAX;
	int n = s.length();
	int d=0;
	vector<int> A(26,0);int diff=0;
	while(j<n)
	{
		cout<<i<<" "<<j<<endl;
		if(A[s[j]-'a']==0)
		{
			A[s[j]-'a']++;
			diff++;
			
		}
		else
		{
			if(s[i]==s[j])
			{
				i++;
			}
			else
			{
				
				A[s[j]-'a']++;
			}
		}
		if(d<diff)
		{
			d=diff;
			result=j-i+1;
			l=i;
		}
		else if(diff==d)
		{
			if(result>(j-i+1))
			{
				result=j-i+1;
				l=i;
			}
		}
		j++;
		cout<<d<<" "<<diff<<" "<<result<<endl;
	}
	if(i!=0&&s[i-1]==s[j-1])
	{
		int k=i;
		for(;k<n-1;k++)
		{
			if(A[s[k]-'a']>1)
			{
				A[s[k]]--;
			}
			else
			{
				break;
			}
		}
		if(j-k<result)
		{
			result=j-k;
		}
	}
	cout<<result<<endl;
	cout<<s.substr(l,result);
	return 0;
	
}
