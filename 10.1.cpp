#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Array
{
//请完成类的设计
	public:
		Array(int n)
		{
			a=new T[n];
		}
		void input(int n);
		T &operator [](int n);
	private:
		T *a;
};	
template <typename T>	
void Array<T>::input(int n)
{
	int i;
	for(i=0;i<n;i++)
	cin>>a[i];
}
template <typename T>
T &Array<T>::operator [](int n)
{
	return a[n];
}
class Fract
{
//请完成类的设计
	public:
      	Fract(int n1=0,int m1=1);
      	void show();
		Fract &operator +=(Fract &b);
		friend istream &operator>>(istream &is, Fract &p);
	private:
		int n,m;
};
Fract::Fract(int n1,int m1)
{
	int k,t;
	n=n1;
	m=m1;
	if(n*m<0)
	t=-1;
	else
	t=1;
	if(n<0)
	n=-n;
	if(m<0)
	m=-m;
	if(n>m)
	k=m;
	else
	k=n;
	for(int i=k;i>1;i--)
	{
		if(n%i==0&&m%i==0)
		{
			n/=i;
			m/=i;
		}
	}
	n=n*t;
}
void Fract::show()
{
	if(n==0)
	cout<<0<<endl;
	else if(m==1)
	cout<<n<<endl;
	else 
	cout<<n<<"/"<<m<<endl;
}
Fract & Fract::operator +=(Fract &k)
{
	Fract c(n*k.m+k.n*m,m*k.m);
	return *this=c;
}
istream &operator>>(istream &is, Fract &p)
    {
        int x, y;
        is>>x>>y;
        Fract temp(x,y);
        p.n=temp.n; p.m=temp.m;
        return is;
    }

int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}

