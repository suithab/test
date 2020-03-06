#include<iostream>
#include<iomanip>
using namespace std;
float fun(float a,float c)
{
	float x;
	x=a-c;
	return x;
}
int main()
{
	float a,b,c,d;
	float m,n;
	cin>>a>>b>>c>>d;
	m=fun(a,c);
	n=fun(b,d);
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<m<<" "<<n;
}
