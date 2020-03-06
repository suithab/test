#include<iostream> 
using namespace std;
int main()
{
	int a[8][8],i,j,n,p=0,r,c;
	char b[8];
	for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	{
		a[i][j]=0;
	}
	cin>>b;
	for(i=0;i<8;i++)
	{
		if(b[i]!='*')
		{
			for(j=0;j<8;j++)
			{
				a[i][j]=1;
				n=b[i]-'1';
				a[j][n]=1; 
			}
			r=i-1;
			c=n-1;
			while(r>=0&&r<=7&&c>=0&&c<=7)
			{
				a[r--][c--]=1;
			}
			r=i+1;
			c=n+1;
			while(r>=0&&r<=7&&c>=0&&c<=7)
			{
				a[r++][c++]=1;
			}
		}
	}
	n=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(a[i][j]==0)
			{
			n=j+1;
			p++;
			}
		}
	}
	if(p==1)
	cout<<n;
	else
	cout<<"No Answer"; 
}

