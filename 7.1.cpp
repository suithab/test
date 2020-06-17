#include<iostream>
using namespace std;
class Complex
{
	public:
		Complex(double x=0,double y=0):real(x),imag(y){};
		Complex operator +(Complex a);
		Complex operator -(Complex a);
		void print();
	private:
		double real,imag;
};
Complex Complex::operator +(Complex a)
{
	Complex c;
	c.real=real+a.real;
	c.imag=imag+a.imag;
	return Complex(c.real,c.imag);
}
Complex Complex::operator -(Complex a)
{
	Complex c;
	c.real=real-a.real;
	c.imag=imag-a.imag;
	return Complex(c.real,c.imag);
}
void Complex::print()
{
	cout<<real<<"+"<<imag<<"i"<<endl;
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

        return  0; 
} 

