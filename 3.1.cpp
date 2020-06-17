#include<iostream>
using namespace std;
class CPoint
{
	public:
		CPoint(int a=0,int b=0);
		CPoint (CPoint &m);
		int getx();
		int gety();
	private:
		int x,y;
};
class CRectangle
{
	public:
		CRectangle();
		CRectangle(CPoint nr,CPoint nw);
		CRectangle(int a,int b,int c,int d);
		CRectangle(CRectangle &n);
		int GetArea();
	private:
		CPoint r,w;	
};
CPoint::CPoint(int a,int b)
{
	x=a;
	y=b;
	cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}
CPoint::CPoint(CPoint &m)
{
	x=m.x;
	y=m.y;
	cout<<"CPoint copy contstructor is called."<<endl;
}
int CPoint::getx()
{
	return x;
}
int CPoint::gety()
{
	return y;
}
CRectangle::CRectangle(CPoint nr,CPoint nw):
					r(nr),w(nw)
{
	cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}
CRectangle::CRectangle(int a,int b,int c,int d):r(a,b),w(c,d)
{
	cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(CRectangle &n):r(n.r),w(n.w)
{
	cout<<"CRectangle copy contstructor is called."<<endl;
}
CRectangle::CRectangle()
{
	cout<<"CRectangle default contstructor is called."<<endl; 
}
int CRectangle::GetArea()
{
	int a,b,s;
	a=r.getx()-w.getx();
	b=r.gety()-w.gety();
	s=a*b;
	if(s<0)
	s=0-s;
	else
	s=s;
}
int  main() 
{ 
        int a=1,b=1,c=6,d=11; 
        cout<<"# Define p1 ######"<<endl; 
        CPoint p1; 
        cout<<"# Define p2 ######"<<endl; 
        CPoint p2(10,20); 
        cout<<"# Define rect1 ######"<<endl; 
        CRectangle rect1; 
        cout<<"# Define rect2 ######"<<endl; 
        CRectangle rect2(p1,  p2); 
        cout<<"# Define rect3 ######"<<endl; 
        CRectangle rect3(a,b,c,d); 
        cout<<"# Define rect4 ######"<<endl; 
        CRectangle rect4(rect2); 
        cout<<"# Calculate area ######"<<endl; 
        cout<<"rect1面积为"<<rect1.GetArea()<<endl; 
        cout<<"rect2面积为"<<rect2.GetArea()<<endl; 
        cout<<"rect3面积为"<<rect3.GetArea()<<endl; 
        cout<<"rect4面积为"<<rect4.GetArea()<<endl; 
        system("pause"); 
        return  0; 
}   
