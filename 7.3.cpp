#include<iostream>
using namespace std;
class Point
{
	public:
		Point (int a=0,int b=0):m_x(a),m_y(b) {};
		Point& operator ++();
		Point operator ++(int);
		friend ostream& operator <<(ostream& output,const Point &c);
	private:
		int m_x,m_y;
};
Point& Point::operator ++()
{
	m_x++;
	m_y++;
	return *this;
}
Point Point::operator ++(int)
{
	Point a=*this;
	++*this;
	return a;
}
ostream& operator <<(ostream &output, const Point &c)
{
	output<<"("<<c.m_x<<","<<c.m_y<<")"<<endl;
	return output;
}
int  main() 
{ 
        Point  a(1,3); 
        cout<<a; 
        cout<<a++;
        cout<<++a; 
        return  0; 
}
