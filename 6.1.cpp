#include<iostream>
using namespace std;
const float pi=3.14159; 
class Shape
{
	public:
		void SetID(int n);
		int GetID();
		int getArea();
		Shape (int m);
		~Shape();
	private:
		int m_ID;
} ;
void Shape::SetID(int n)
{
	m_ID=n;
}
int Shape::GetID()
{
	return m_ID;
}
int Shape::getArea()
{
	return 0;
}
Shape::Shape(int m)
{
	m_ID=m;
	cout<<"Shape constructor called:"<<m_ID<<endl;
}
Shape::~Shape()
{
	cout<<"Shape destructor called:"<<m_ID<<endl;
}
class Circle:protected Shape
{
	public:
		void Setr(int n);
		int Getr();
		float getArea();
		Circle (int i,int j);
		~Circle ();
	private:
		int r;
};
void Circle::Setr(int n)
{
	r=n;
}
int Circle::Getr()
{
	return r;
}
float Circle::getArea()
{
	float s;
	s=pi*r*r;
	return s;
}
Circle::Circle(int i,int j):Shape(j)
{
	r=i;
	cout<<"Circle constructor called:"<<Shape::GetID()<<endl; 
}
Circle::~Circle()
{
	cout<<"Circle destructor called:"<<Shape::GetID()<<endl;
}
class Rectangle:public Shape
{
	public:
		void SetH(int hi);
		void SetW(int wi);
		int GetH();
		int GetW();
		int getArea();
		Rectangle (int a,int b,int c);
		~Rectangle ();
	private:
		int h,w;
};
void Rectangle::SetH(int hi)
{
	h=hi;
}
void Rectangle::SetW(int wi)
{
	w=wi;
}
int Rectangle::GetH()
{
	return h;
}
int Rectangle::GetW()
{
	return w;
}
int Rectangle::getArea()
{
	int s;
	s=h*w;
	return s;
}
Rectangle::Rectangle(int a,int b,int c):Shape(c)
{
	h=a;
	w=b;
	cout<<"Rectangle constructor called:"<<Shape::GetID()<<endl;
}
Rectangle::~Rectangle()
{
	cout<<"Rectangle destructor called:"<<Shape::GetID()<<endl;
}
int  main() 
{ 
        Shape s(1);//1表示ID 
        Circle c(4,2);//4表示半径，2表示ID 
        Rectangle r(4,5,3);//4和5表示长和宽，3表示ID 
        cout<<"Shape的面积"<<s.getArea()<<endl; 
        cout<<"Circle的面积"<<c.getArea()<<endl; 
        cout<<"Rectangle的面积"<<r.getArea()<<endl; 
}
