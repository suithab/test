#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	short stu_id,score;
};
int main()
{
	int n,i;
	cin>>n;
	student *a=new student[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i].stu_id>>a[i].score;
	}
	ofstream file1("out.txt",ios::binary);
	if(!file1)
  {
    cout<<"error"<<endl;
	exit(1);  
  }
	file1.write((char*)a,sizeof(a)*n);
	file1.close();

	student *b=new student[n];
	ifstream file2("out.txt",ios::binary);
	//file2.seekg(0,file2.end);
	//int length=file2.tellg();
	//file2.seekg(0,file2.beg);
	if(!file2)
  {
    cout<<"error"<<endl;
	exit(1);  
  }
  	i=0;
    while(!file2.eof())
  	{
		file2.read((char*)&b[i++],sizeof b);
		
	}
	file2.close();
	ofstream file3("out.txt",ios::ate);
	file3.write((char*)b,sizeof(b)*n);
	file3.close();
	//delete []b;
	return 0;
}
