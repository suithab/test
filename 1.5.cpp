#include<iostream> 
using namespace std;
int main()
{
	int a[8][8],b[8],i,j,k,m=0,p=0;
	for(i=0;i<8;i++)
	{
		cin>>b[i];
		if(b[i]!='*')
		{
			for(j=0;j<8;j++)
			{
				a[i][j]=1;
				a[j][b[i]]=1; 
			}
			for(k=0;m<8;k++)
			{
				m=k+b[i]-i;
				a[k][m]=1;
			}
		}
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(a[i][j]!=1)
			break;
			p++;
		}
	}
	if(p==64)
	cout<<"No answer";
	else
	cout<<i; 
}

