#include<iostream> 
using namespace std; 
class Book 
{ 
//请在此处补充Book类的定义 
 public:
 	void SetID(int ID);
 	void SetName(string name);
 	void SetIntroduction(string introduction);
 	void SetAuthor(string author);
 	void SetDate(string date);
 	void SetPage(int page);
 	int GetID();
 	string GetName();
 	string GetIntroductio();
 	string GetAuthor();
 	string GetDate();
 	int GetPage();
 	Book();
 	Book(const Book &other);
	~Book();
 private:
 	unsigned int m_ID;
 	string m_Name;
 	string m_Introduction;
 	string m_Author;
 	string m_Date;
 	unsigned int m_Page;
}; 
//请在此处补充Book类的成员函数实现 
void Book::SetID(int ID)
{
	m_ID=ID;
}
void Book::SetAuthor(string author)
{
	m_Author=author;
}
void Book::SetName(string name)
{
	m_Name=name;
}
void Book::SetIntroduction(string introduction)
{
	m_Introduction=introduction;
}
void Book::SetDate(string date)
{
	m_Date=date;
}
void Book::SetPage(int page)
{
	m_Page=page;
}
int Book::GetID()
{
	return m_ID;
}
string Book::GetAuthor()
{
	return m_Author;
}
string Book::GetName()
{
	return m_Name;
}
string Book::GetIntroductio()
{
	return m_Introduction;
}
string Book::GetDate()
{
	return m_Date;
}
int Book::GetPage()
{
	return m_Page;
}
Book::Book()
{
	m_ID=0;
}
Book::Book(const Book &other)
{
	m_ID=other.m_ID;
	m_Author=other.m_Author;
	m_Name=other.m_Name;
	m_Introduction=other.m_Introduction;
	m_Date=other.m_Date;
	m_Page=other.m_Page; 
}
Book::~Book()
{
	
}
class  Store 
{ 
//请在此处补充Store类的定义
 public:
	void SetCount(int n);
	int GetCount();
	Store();
	Store(int n);
	~Store();
	Store(const Store &n);
	void in(Book &b);
	void out(string name);
	Book findbyID(int ID);
	Book findbyName(string name);
	void printList();
 private:
 	Book *m_pBook;
 	unsigned int m_Count;
}; 
//请在此处补充Store类的成员函数实现
void Store::SetCount(int n)
{
	m_Count=n;
}  
int Store::GetCount()
{
	return m_Count;
}
Store::Store()
{
	m_Count=0;
	m_pBook=0;
	cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n)
{
	m_Count=n;
	m_pBook=new Book[n];
	cout<<"Store constructor with (int n) called!"<<endl;
}
Store::~Store()
{
	m_Count=0;
	if(m_pBook!=NULL)
	delete [] m_pBook;
	cout<<"Store destructor called!"<<endl;
}
void Store::in(Book &b)
{
	int i;
	Book *book=new Book[m_Count+1];
	for(i=0;i<m_Count;i++)
	{
		book[i]=m_pBook[i];
	}
	book[i]=b;
	m_pBook=book;
	m_Count+=1;
}
void Store::out(string name)
{
	int i;
	Book *book=new Book[m_Count-1];
	for(i=0;i<m_Count-1;i++)
	{
		if(m_pBook[i].GetName()==name)
		{
			book[i]=m_pBook[i+1];
		}
		else
		book[i]=m_pBook[i];
	}
	m_pBook=book;
	m_Count-=1;
}
Book Store::findbyID(int ID)
{
	int i;
	Book book;
	for(i=0;i<m_Count;i++)
	{
		if(m_pBook[i].GetID()==ID)
		{
			return m_pBook[i];
			break;
		}
	}
	if(i==m_Count)
	{
		return book;
	}
}
Book Store::findbyName(string name)
{
	int i;
	Book book;
	for(i=0;i<m_Count;i++)
	{
		if(m_pBook[i].GetName()==name)
		{
			return m_pBook[i];
			break;
		}
	}
	if(i==m_Count)
	{
		return book;
	}
}
void Store::printList()
{
	int i;
	cout<<"There are totally "<<m_Count<<" Books:"<<endl;
	for(i=0;i<m_Count;i++)
	{
		cout<<"ID="<<m_pBook[i].GetID()<<"; ";
		cout<<"Name:"<<m_pBook[i].GetName()<<"; ";
		cout<<"Author:"<<m_pBook[i].GetAuthor()<<"; ";
		cout<<"Date:"<<m_pBook[i].GetDate()<<"; ";
		cout<<endl;
	}
}
int  main() 
{ 
    Store  s; 
    Book  b1,b2,b3; 
    b1.SetID(1); 
    b1.SetName("C++  语言程序设计(第4版)"); 
    b1.SetAuthor("郑莉"); 
    b1.SetIntroduction("介绍C++及面向对象的知识"); 
    b1.SetDate("201007"); 
    b1.SetPage(529); 
    b2.SetID(2); 
    b2.SetName("离散数学"); 
    b2.SetAuthor("左孝凌"); 
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论"); 
    b2.SetDate("198209"); 
    b2.SetPage(305); 
    b3.SetID(3); 
    b3.SetName("c程序设计"); 
    b3.SetAuthor("谭浩强"); 
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等"); 
    b3.SetDate("201006"); 
    b3.SetPage(355); 
    cout<<"第一本书入库"<<endl; 
    s.in(b1); 
    cout<<"第二本书入库"<<endl; 
    s.in(b2); 
    cout<<"第三本书入库"<<endl; 
    s.in(b3); 
    cout<<"现有库存书籍数量："<<s.GetCount()<<endl; 
    cout<<"查找并出库图书：离散数学"<<endl; 
	Book tmpbook=s.findbyName("离散数学"); 
    if(tmpbook.GetID()!=0) 
    { 
        s.out("离散数学"); 
        cout<<"离散数学  已成功出库"<<endl; 
    } 
    else 
    cout<<"没有找到name为离散数学的书"<<endl; 
    cout<<"现有库存书籍数量："<<s.GetCount()<<endl; 
    cout  <<"查找图书  ID：3"  <<  endl; 
    tmpbook=s.findbyID(3); 
    if(tmpbook.GetID()!=0) 
    cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl; 
    else 
    cout<<"没有找到ID为"<<3<<"的书"<<endl; 
    cout  <<"查找图书  name：离散数学"  <<  endl; 
    tmpbook=s.findbyName("离散数学"); 
    if(tmpbook.GetID()!=0) 
    cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl; 
    else 
    cout<<"没有找到name为离散数学的书"<<endl; 
    cout<<"输出所有库存图书的信息"<<endl; 
    s.printList(); 
    cout<<"程序运行结束"<<endl; 
    return  0; 
}
