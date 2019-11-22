#include<iostream>
#include<sstream>
using namespace std;

string solve(int y)
{	
    int z=y;
    stringstream convert;
	string res; 
	convert << y;
	res = convert.str();
	string str;
	if(y<=1917)
	{
		int p;
		p=y%4;
		if(p==0)
		{
			str = "12.09.";
			str += res;
		}
		else
		{
			str = "13.09.";
			str += res;
		}
	}
	else if(y==1918)
	{
		str="26.09.";
		str += res;;
	}
	else if(y>1918)
	{
		int k,s,t;
		k=y%400;
		s=y%4;
		t=y%100;
		if((k==0)||(s==0&&t!=0))
		{
			str = "12.09.";
			str += res;
		}
		else {
			str = "13.09.";
			str += res;
		}
	}
	return str;
}
int main()
{
	int y;
	cin>>y;
	string pro = solve(y);
	cout<<pro;
	return 0;
}

