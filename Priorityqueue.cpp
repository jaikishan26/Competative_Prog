#include<bits/stdc++.h>
using namespace std;
void change(vector<int> &v, int i, int val)
{
	if(val<v[i])
	return;
	v[i]=val;
	while(i>1&&v[i/2]<v[i])
	{
		swap(v[i],v[i/2]);
		i=i/2;
	}
}
void insert(vector<int> &v, int val)
{
	v.push_back(-1);
	//cout<<v.size()<<endl;
	change(v,v.size()-1,val);
}
int currentmax(vector<int> v)
{
	if(v.size()==1)
	return INT_MAX;
	return v[1];
}
void maxheapify(vector<int> &v,int i, int n)
{
	int largest=i;
	int left=2*i;
	int right=2*i+1;
	if(left<=n&&v[left]>v[i])
	largest=left;
	if(right<=n&&v[right]>v[largest])
	largest=right;
	if(largest!=i)
	{
		swap(v[largest],v[i]);
		maxheapify(v,largest,n);
	}
}
int main()
{
	int n;
	vector<int> v;
	v.push_back(INT_MIN);
	cin>>n;
	int p;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		insert(v,p);
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<v[i]<<" ";
	}*/
	cout<<endl;
	int q;
	while(q--)
	{
		int x,y;
		cin>>x;
		if(x==1)
		{
			cin>>y;
			insert(v,y);
		}
		else if(x==2)
		{
			cout<<currentmax(v);
			cout<<endl;
		}
		
	}
	return 0;
}
