#include<iostream>
using namespace std;
int fun(int a,int b,int c)
{ 
	b+=a;
	c+=a;
	if((b/2+c/3)==0)
	return a;
	else
	return a+fun(b/2+c/3,b%2,c%3);
}
int main()
{
	int money,b;
	cin>>money;
	b=fun(money,0,0);
	cout<<b;
}
