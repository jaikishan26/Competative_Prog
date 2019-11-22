#include<iostream>
using namespace std;
int A[51][51];
struct node
{
	int x;
	int y;
	int d;
};
node queue[3000];
bool visited[51][51];
int rear;
int front;

bool valid(int a, int b,int n, int m)
{
	if(a>=0&&b>=0&&a<n&&b<m)
	return true;
	return false;
}

void get()
{
	rear=0;
	front=0;
	return;
}

node pop()
{
	node p;
	p.x=-1;
	p.y=-1;
	p.d=-1;
	if(rear==front)
	return p;
	node dummy = queue[front];
	front++;
	return dummy;
}

void push(node s)
{
	queue[rear]=s;
	rear++;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int r,c;
		cin>>r>>c;
		int l;
		cin>>l;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>A[i][j];
				visited[i][j]=false;
			}
		}
		get();
		node p;
		p.x=r;
		p.y=c;
		p.d=l-1;
		push(p);
		visited[r][c]=true;
		int X1[] = {0,0,1,-1};
		int Y1[]= {-1,1,0,0};
		int X2[]= {1,-1};
		int Y2[]= {0,0};
		int X3[] = {0,0};
		int Y3[] = {1,-1};
		int X4[]={0,-1};
		int Y4[]={1,0};
		int X5[]={0,1};
		int Y5[]={1,0};
		int X6[]={0,1};
		int Y6[]={-1,0};
		int X7[]={0,-1};
		int Y7[]={-1,0};
		while(rear!=front)
		{
			node temp = pop();
			cout<<temp.x<<temp.y<<temp.d<<endl;
			if(temp.d==0)
			continue;
		/*	bool b = pop();
			if(!b)*/
			int num = A[temp.x][temp.y];
			cout<<num<<" *"<<endl;
			if(A[temp.x][temp.y]==1)
			{
				for(int i=0;i<4;i++)
				{
					int a1 = temp.x+ X1[i];
					int a2 = temp.y + Y1[i];
					if(valid(a1,a2,n,m)&&visited[a1][a2]==false)
					{
					    node temp1;
						temp1.x=a1;
						temp1.y=a2;
						temp1.d = temp.d-1;
						visited[a1][a2]=true;
						push(temp1);
					}
				}
			}
			else if(num==2)
			{
				for(int i=0;i<2;i++)
				{
					int a1 = temp.x+ X2[i];
					int a2 = temp.y + Y2[i];
					if(valid(a1,a2,n,m)&&visited[a1][a2]==false)
					{
					    node temp1;
						temp1.x=a1;
						temp1.y=a2;
						temp1.d = temp.d-1;
						visited[a1][a2]=true;
						push(temp1);
					} 
				}
			}
			else if(num==3)
			{
				for(int i=0;i<2;i++)
				{
					int a1 = temp.x+ X3[i];
					int a2 = temp.y + Y3[i];
					if(valid(a1,a2,n,m)&&visited[a1][a2]==false)
					{
					    node temp1;
						temp1.x=a1;
						temp1.y=a2;
						temp1.d = temp.d-1;
						visited[a1][a2]=true;
						push(temp1);
					} 
				}
			}
			else if(num==4)
			{
				for(int i=0;i<2;i++)
				{
					int a1 = temp.x+ X4[i];
					int a2 = temp.y + Y4[i];
					if(valid(a1,a2,n,m)&&visited[a1][a2]==false)
					{
					    node temp1;
						temp1.x=a1;
						temp1.y=a2;
						temp1.d = temp.d-1;
						visited[a1][a2]=true;
						push(temp1);
					} 
				}
			}
			else if(num==5)
			{
				for(int i=0;i<2;i++)
				{
					int a1 = temp.x+ X5[i];
					int a2 = temp.y + Y5[i];
					if(valid(a1,a2,n,m)&&visited[a1][a2]==false)
					{
					    node temp1;
						temp1.x=a1;
						temp1.y=a2;
						temp1.d = temp.d-1;
						visited[a1][a2]=true;
						push(temp1);
					} 
				}
			}
			else if(num==6)
			{
				for(int i=0;i<2;i++)
				{
					int a1 = temp.x+ X6[i];
					int a2 = temp.y + Y6[i];
					if(valid(a1,a2,n,m)&&visited[a1][a2]==false)
					{
					    node temp1;
						temp1.x=a1;
						temp1.y=a2;
						temp1.d = temp.d-1;
						visited[a1][a2]=true;
						push(temp1);
					}
				}
			}
			else if(num==7)
			{
				for(int i=0;i<2;i++)
				{
					int a1 = temp.x+ X7[i];
					int a2 = temp.y + Y7[i];
					if(valid(a1,a2,n,m)&&visited[a1][a2]==false)
					{
					    node temp1;
						temp1.x=a1;
						temp1.y=a2;
						temp1.d = temp.d-1;
						visited[a1][a2]=true;
						push(temp1);
					}
				}
			}
			
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<visited[i][j]<<" ";
				if(visited[i][j]==1)
				{
					count++;
				}
			}
			cout<<endl;
		}
		cout<<count;
	}
}
