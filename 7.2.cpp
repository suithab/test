#include<iostream>
using namespace std;
class Complex
{
	public:
		Complex(double x=0,double y=0):real(x),imag(y){};
		friend Complex operator +(Complex a,Complex b);
		friend Complex operator -(Complex a,Complex b);
		void print();
	private:
		double real,imag;
};
Complex operator +(Complex a,Complex b)
{
	return Complex(a.real+b.real,a.imag+b.imag);
}
Complex operator -(Complex a,Complex b)
{
	return Complex(a.real-b.real,a.imag-b.imag);
}
void Complex::print()
{
	cout<<"("<<real<<")"<<"+"<<"("<<imag<<"i"<<")"<<endl;
}
int  main() 
{ 
        Complex  a(3,4),b(1,-1),c; 
        c=a+b; 
        cout<<"a+b="; 
        c.print(); 
        cout<<endl; 
        c=a-b; 
        cout<<"a-b="; 
        c.print(); 
        cout<<endl; 
        c=a+100; 
        cout<<"a+100="; 
        c.print(); 
        cout<<endl; 
        c=a-2.5; 
        cout<<"a-2.5="; 
        c.print(); 
        cout<<endl; 
        c=100+a; 
        cout<<"100+a="; 
        c.print(); 
        cout<<endl; 
        c=2.5-a; 
        cout<<"2.5-a="; 
        c.print(); 
        cout<<endl; 
        return  0; 
} 
