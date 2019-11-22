#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<string> A{"What", "must", "be", "shall", "be."};
    vector<string> v;
    int n = A.size();
    /*if(n==1)
    {
        v.push_back(A[0]);
        return v;
    }*/
    int i=0;
    while(i<n)
    {
        int sum=0;
        int count=0;
        string temp="";
        while(sum<=B&&i<n)
        {
            sum+=A[i].length();
            count++;
            if((B-sum)<(count-1))
            {
                sum-=(A[i].length());
                count--;
                break;
            }
            i++;
        }
        int x = B-sum;
        if(i==n)
        {
            while(count>0)
            {
                temp= temp+v[i-count]+" ";
                count--;
            }
            //temp.pop_back();
            x=B-temp.length();
            while(x>0)
            {
                temp+=" ";
                x--;
            }
            //cout<<temp<<endl;
            v.push_back(temp);
            break;
        }
        else if(count==1) 
        {
            temp+=A[i-count];
            while(x--)
            {
                temp+=" ";
            }
            v.push_back(temp);
        }
        else if(count != 1 && x%(count-1) ==0)
        {
            int y = x/(count-1);
            while(count>0)
            {
                int g=y;
                temp+=v[i-count];
                count--;
                while(g>0 && count>0)
                {
                    temp+=" ";
                    g--;
                }
            }
            v.push_back(temp);
        }
        else if(count != 1 && x%(count-1) !=0)
        {
            bool flag=false;
            int y = x/(count-1);
            int z = x%(count-1);
            int p=y+z;
            while(count>0)
            {
                if(flag==false&&count>0)
                {
                    temp+=A[i-count];
                    while(p--)
                    {
                        temp+=" ";
                    }
                    count--;
                    flag=true;
                }
                else
                {
                    int g=y;
                    temp+=v[i-count];
                    count--;
                    while(g>0&&count>0)
                    {
                        temp+=" ";
                        g--;
                    }
                }
            }
            v.push_back(temp);
        }
    }
    for(int r=0;r<v.length();r++)
    {
    	cout<<v[r]<<endl;
	}
return 0;

}
