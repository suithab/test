#include<iostream>
using namespace std;
int main()
{
	int a[3][3],b[3][3];
	int i,j,k,m=0,n=0,p;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>a[i][j];
		}	
	}
	cout<<endl; 
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>b[i][j];
		}	
	}
	for(p=0;p<3;p++)
	for(i=0;i<3;i++)
	{
		k=0;
		for(j=0;j<3;j++)
		{
			k=a[n][j]*b[j][i]+k;
		}
		cout<<k<<" ";
		m++;
		if(m%3==0)
		{
			cout<<endl;
			n++;
		}	
	}
	return 0;
}
