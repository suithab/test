#include<iostream>
#include<iomanip>
#include <malloc.h>
using namespace std;
template <class T>
class Node
{
	public:
		Node<T> *next;
		T data;
};
template <class T>
class linkedList
{
	public:
    linkedList();//构造函数
    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
    void insert( T value );//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    bool isEmpty();//判断单链表是否为空
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove( int pos, T& value );
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    Node<T> *head;
    int len;
};
template <class T>
linkedList<T>::linkedList()
{
	len=0;
}
template <class T>
linkedList<T>::~linkedList()
{
	if(len==0)
	delete head;
	Node<T> *p;
	while(head->next!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
	delete head;
	head=NULL;
}
template <class T>
void linkedList<T>::insert(T value)
{
	len++;
	int i=0;
	Node<T> *p;
	Node<T> *q=new Node<T>();
	p=head;
	while(p!=NULL&&i<len-1)
	{
		p=p->next;
		i++;
	}
	q->data=value;
	q->next=p->next;
	p->next=q;
}
template <class T>
bool linkedList<T>::initiate()
{
	head=new Node<T>();
	head->next=NULL;
	if(head!=NULL)
	return true;
	else
	return false;
}
template <class T>
bool linkedList<T>::isEmpty()
{
	if(head->next==NULL||head==NULL)
	return true;
	else
	return false;
}
template <class T>
bool linkedList<T>::remove(int pos,T & value)
{
	Node<T> *q,*p;
	int i=0;
	q=head;
	p=head->next;
	while(p!=NULL&&i<pos-1)
	{
		q=p;
		p=p->next;
		i++;
	}
	if(pos<=0)
	{
		cout<<"pos <=0 ,failed"<<endl;
		return false;
	}
	if(!p||i>pos-1)
	{
		cout<<"pos > len,failed"<<endl;
		return false;
	}
	else
	{
		q->next=p->next;
		value=p->data;
		free(p);
		len--;
		return ture;
	}
}
template <class T>
int linkedList<T>::Length()
{
	return len;
}
//成员函数print
template <class T>
void linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    Node<T>* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}

