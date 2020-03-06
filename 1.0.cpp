#include<iostream> 
#include<math.h>
#include<string.h>
using namespace std;
void fun(char x[10])
{
	int i;
	for(i=0;i<10;i++)
	{
		if(x[i]>='A'&&x[i]<='Z')
		x[i]+=32;	
	}	
}
int main()
{
	char a[10],b[10];
	int h1,h2,i,j,k=0,c[100],min;
	cin>>a;
	cin>>b;
	fun(a);
	fun(b);
	h1=strlen(a);
	h2=strlen(b);
	for(i=0;i<h1;i++)
	{
		for(j=0;j<h2;j++)
		{
			c[k++]=abs(a[i]-b[j]);
		}
	}
	min=c[0];
	for(i=0;i<k;i++)
	{
		if(c[i]==0)
		{
			cout<<0;
			break;
		}
		if(min>=c[i])
		min=c[i];
	}
	if(i==k)
	cout<<min;
}
