#include<iostream>
using namespace std;
 void knapsack(int val[], int weight[], int w, int n)
 {
 	int res[n+1][w+1];
 	for(int i=0;i<n+1;i++)
 	{
 		res[i][0]=0;
	}
	for(int i=0;i<w+1;i++)
	{
		res[0][i]=0;
	}
 	for(int i=1;i<n+1;i++)
 	{
 		for(int j=1;j<w+1;j++)
 		{
 			if(weight[i-1]>j)
 			{
 				res[i][j]=res[i-1][j];
			}
			else
			{
				res[i][j]= max((val[i-1]+res[i-1][j-weight[i-1]]),res[i-1][j]);
			}
			//cout<<res[i][j]<<" ";
		}
		//cout<<endl;
	 }
	 //cout<<endl;
	 int max=res[n-1][w];
	 cout<<max<<endl;
	 
	 for(int i=n;i>=0;i--)
	 {
	 	for(int j=w;j>=0;j--)
	 	{
	 		if(res[i][j]==0)
	 		break;
			if(res[i][j] ==res[i-1][j])
	 		{
	 			i=i-1;
			}
			else if(res[i][j]== res[i][j-1])
			{
				j=j-1;
			}
			else
			{
				cout<<val[i-1]<<" ";
				j=j-1;
				i = i - val[i-1];
			}
		}
	 }
	 //return max;
 }

int main()
{
	int val[] = {1, 4, 5, 7};
	int weight[] = {1, 3, 4, 5};
	int w=7;
	knapsack(val, weight, w,4);
}
