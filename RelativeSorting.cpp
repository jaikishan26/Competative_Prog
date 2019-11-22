#include <bits/stdc++.h>
using namespace std;

int BSleft(vector<int> v, int k)
{
    int l=0;
    int r=v.size()-1;
    int mid;
    int ans=-1;
    while(l<r)
    {
         mid = l + (r-l)/2;
        if(v[mid]==k)
        {
            ans=mid;
            r=mid-1;
        }
        else if(v[mid]>k)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}

int BSright(vector<int> v, int k)
{
    int l=0;
    int r=v.size()-1;
    int mid;
    int ans=-1;
    while(l<r)
    {
         mid = l + (r-l)/2;
        if(v[mid]==k)
        {
            ans=mid;
            l = mid+1;
        }
        else if(v[mid]>k)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<int> a(n);
	    vector<int> b(m);
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=0;i<m;i++)
	    {
	        cin>>b[i];
	    }
	    sort(a.begin(),a.end());
	    int j=0;
	    for(int i=0;i<m;i++)
	    {
	        int l = BSleft(a,b[0]);
	        int r = BSright(a,b[0]);
	        while(l<=r &&j<n)
	        {
	            swap(a[j],a[l]);
	            l++;
	            j++;
	        }
	    }
	    if(j!=n)
	    sort(a.begin()+j, a.end());
	    for(int i=0;i<n;i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
