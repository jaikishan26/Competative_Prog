#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(A)/sizeof(int);
    if(n==0)
   	cout<<0;
    else if(n<0)
    cout<<-1;
    else 
    {
        int maxreach=A[0];
        int step=A[0];
        int jump=1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)
            {
                cout<<jump;
            }
            if(maxreach<i+A[i])
            {
                maxreach = i+A[i];
            }
            step--;
            if(step==0)
            {
                step=maxreach-i;
                jump=jump+1;
            }
        }
        //cout<<jump;
    }
}
