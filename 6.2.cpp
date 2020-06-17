#include"iostream" 
using namespace std; 
class vehicle
{
	public:
		vehicle (int i,int j);
		void run();
		void stop();
		~vehicle();
	private:
		int maxspeed,weight;		
};
vehicle::vehicle(int i,int j)
{
	maxspeed=i;
	weight=j;
	cout<<"vehicle constructor called.maxspeed:"<<maxspeed<<";weight"<<weight<<endl;
} 
void vehicle::run()
{
	cout<<"vehicle run"<<endl;
}
void vehicle::stop()
{
	cout<<"vehicle stop"<<endl;
}
vehicle::~vehicle()
{
	cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<";weight"<<weight<<endl;
}
class bicycle:virtual public vehicle
{
	public:
		bicycle(int i,int j,int k);
		~bicycle();
	private:
		int height;	
};
bicycle::bicycle(int i,int j,int k):vehicle(i,j)
{
	height=k;
	cout<<"bicycle constructor called. height:"<<height<<endl;
}
bicycle::~bicycle()
{
	cout<<"bicycle destructor called. height:"<<height<<endl;
}
class motorcar:virtual public vehicle
{
	public:
		motorcar(int i,int j,int k);
		~motorcar();
	private:
		int seatnum;
};
motorcar::motorcar(int i,int j,int k):vehicle(i,j)
{
	seatnum=k;
	cout<<"motorcar constructor called. seatnum:"<<seatnum<<endl;
}
motorcar::~motorcar()
{
	cout<<"motorcar destructor called. seatnum:"<<seatnum<<endl;
}
class motorcycle:public bicycle,public motorcar
{
	public:
		motorcycle(int i,int j,int k,int n);
		~motorcycle();
};
motorcycle::motorcycle(int i,int j,int k,int n):vehicle(k,n),bicycle(k,n,i),motorcar(k,n,j)
{
	cout<<"motorcycle constructor called"<<endl;
}
motorcycle::~motorcycle()
{
	cout<<"motorcycle destructor called"<<endl;
}
int main(int argc,char *argv[]) 
{ 
    motorcycle m(1,2,3,4);//1表示height，2表示setnum，3表示maxspeed，4表示weight 
    m.run(); 
    m.stop(); 
    return  0; 
}
