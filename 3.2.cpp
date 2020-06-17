#include<iostream>
using namespace std;
class Car;
class Boat
{  
	public:
		Boat(int nw);
		friend int totalweight(Boat& b,Car& c);
	private:
		int weight;
};
class Car
{
	public:
		Car(int nw);
		friend int totalweight(Boat& b,Car& c);
	private:
		int weight;
};
Boat::Boat(int nw)
{
	weight=nw;
}
Car::Car(int nw)
{
	weight=nw;
}
int  totalweight(Boat& b,Car& c) 
{ 
    return  b.weight+c.weight; 
} 
int  main() 
{ 
    Boat b(100); 
    Car c(200); 
    cout<<totalweight(b,c)<<endl; 
    return 0; 
} 
