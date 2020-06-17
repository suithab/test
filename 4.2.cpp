#include<iostream>
#include<string>
using namespace std;
class CStudent
{
	public:
		CStudent();
		CStudent(string newname,int newage);
		~CStudent();
		static int getcount();
		void printname();
	private:
	 string name;
	 int age;
	 static int count;	
};
CStudent::CStudent()
{
	count++;
	cout<<"noname is contructing"<<endl;
}
CStudent::CStudent(string newname,int newage)
{
	count++;
	name=newname;
	age=newage;
	cout<<newname<<" is contructing"<<endl;
}
CStudent::~CStudent()
{
	count--;
		int n;
	n=name.length();
	if(n==0)
	cout<<"noname is destructing"<<endl;
	else
	cout<<name<<" is destructing"<<endl;
} 
int CStudent::getcount()
{
	return count;
}
void CStudent::printname()
{
	int n;
	n=name.length();
	if(n==0)
	cout<<"name:noname"<<endl;
	else
	cout<<"name:"<<name<<endl;
}
int CStudent::count=0;
int main() 
{ 
    cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    { 
        CStudent  stuB[5]; 
        stuB[4].printname(); 
        cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    } 
    cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    { 
        CStudent stuA[2]={CStudent("Tom",3),CStudent("Jerry",2)}; 
        for(int i=0;i<2;i++) 
        { 
            stuA[i].printname(); 
        } 
        cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    } 
    cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    return  0; 
}

