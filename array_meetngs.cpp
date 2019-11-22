#include <iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    int s[n];
	    int f[n];
	    for(int j=0;j<n;j++)
	    {
	        cin>>s[j];
	    }
	    for(int k=0;k<n;k++)
	    {
	        cin>>f[i];
	    }
	    vector<int, int> m;
	    for(int p=0;p<n;p++)
	    {
	        m.push_back(f[p], s[p]);
	    }
	    sort(m.begin(), m.end());
	    
	    int count=1;
	    int y=0;
	    for(int r=1;r<n;r++)
	    {
	        if((m[r]->second)>=(m[y]->first))
	        {
	            count++;
	            y=r;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
