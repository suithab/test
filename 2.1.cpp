#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double PI=3.1415926;
class cylinder
{
	public:
		double getvolumn();
		double getarea();
		cylinder (double a,double b);
		~cylinder();
	private:
		double r,h;
};
double cylinder :: getvolumn()
{
	double v;
	v=h*PI*pow(r,2);
	return v;
}
double cylinder ::getarea()
{
    double s,s1;
    s1=PI*r*r;
    s=h*PI*r*2.0+s1*2.0;
    return s;
}
cylinder ::cylinder(double a,double b)
{
	h=a;
	r=b;
	cout<<"构造函数被调用"<<endl; 
}
cylinder ::~cylinder()
{
	cout<<"析构函数被调用"<<endl; 
}
int main()
{
	double d,h;
	cin>>d>>h;
	cylinder can(h,d/2);
	cout<<fixed<<setprecision(6);
	cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
	cout<<"铁皮的面积是"<<can.getarea()<<endl; 
 } 
