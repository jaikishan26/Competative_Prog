#include<bits/stdc++.h>
using namespace std;
int func(vector<vector<double> > &memo, string S, int s, int k)
{
	if(memo[s][k]!=-1)
	return memo[s][k];
	if(k==1)
	{
		memo[s][k]=stoi(S.substr(s,S.length()-s));
		return memo[s][k];
	}
	int ans=0;
	string temp="";
	for(int i=s;i+k<=S.length();i++)
	{
		temp+=S[i];
		ans=max(ans,max(stoi(temp),func(memo,S,i+1,k-1)));
	}
	memo[s][k]=ans;
	return ans;
}
    int main()
    {
        string s;
    	cin>>s;
    	int k=0;
    	cin>>k;
    	int n = s.size();
		vector<vector<int> > memo(n+1,vector<int>(k+1,-1));
        return func(memo,A,sum,0,k);
	}
