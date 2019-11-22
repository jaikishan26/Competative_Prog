#include<bits/stdc++.h>
using namespace std;

string permutation(string s, int n)
{
    int a[26];
    memset(a,0,sizeof(a));
    vector<long long int> fac(20);
    fac[0]=1;
    for(int i=1;i<20;i++)
    {
        fac[i]=i*fac[i-1];
    }
    for(int i=0;i<s.length();i++)
    {
        a[s[i]-'a']++;
    }
    int m = s.length();
    if(n==1)
    return s;
    int sum=0;
    string ans="";
    int k=0;
    cout<<s<<endl;
    while(sum!=n)
    {
        sum=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]==0)
            continue;
            a[i]--;
            long long int p = fac[m-1-k];
            for(int j=0;j<26;j++)
            {
                if(a[j]<=1)
                continue;
                p/=fac[a[j]];
            }
            sum+=p;
            if(sum>=n)
            {
                k++;
                ans+=(i+'a');
                n-=(sum-p);
                break;
            }
            if(sum<n)
            {
                a[i]++;
            }
        }
        //cout<<ans<<endl;
    }
    for(int i=25;i>=0,k<m;i--)
    {
        if(a[i]>0)
        {
            ans+=(i+'a');
            k++;
            a[i++]--;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    cout<<permutation(s,n);
    return 0;
}
