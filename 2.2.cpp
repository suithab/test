#include<iostream>
#include<cmath>
using namespace std;
class CTime
{
	public:
		CTime (int ny,int nm,int nd,int nh,int m,int ns);
		CTime (CTime &c);
		~CTime();
		int dayDiff(CTime t);
		void showTime();
		int isvalid();
	private:
		int year,month,day,hour,minte,second;
};
CTime::CTime(int ny,int nm,int nd,int nh=0,int m=0,int ns=0)
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31},k;
	if((ny%4==0&&ny%100!=0)||(ny%400==0))
	k=1;
	else
	k=0;
	if(k==1)
	a[1]=29;
	if(nm>0&&nm<=12&&nd>0&&nd<=31&&nh>=0&&nh<=23&&m>=0&&m<=59&&ns>=0&&ns<=59)
	{
		if(a[nm-1]>=nd)
		{
			year=ny;
	        month=nm;
			day=nd;
			hour=nh;
			minte=m;
			second=ns;
		}
		else
		{
			cout<<"date error!"<<endl;
			year=0;
			month=0;
			day=0;
			hour=0;
			minte=0;
			second=0;
		}
	}
	else if(nm>12||nd>31)
	{
		cout<<"date error!"<<endl;
			year=0;
			month=0;
			day=0;
			hour=0;
			minte=0;
			second=0;
	}
	else if(nh>23||m>59||ns>59)
	{
		cout<<"time error!"<<endl;
		year=0;
		month=0;
		day=0;
		hour=0;
		minte=0;
		second=0;
	}
	else
	{
		cout<<"date and time error!"<<endl;
		year=0;
		month=0;
		day=0;
		hour=0;
		minte=0;
		second=0;
	}
	cout<<"构造函数被调用"<<endl; 
}
CTime::CTime(CTime &c)
{
	year=c.year;
	month=c.month;
	day=c.day;
	hour=c.hour;
	minte=c.minte;
	second=c.second;
	cout<<"拷贝构造函数被调用"<<endl; 
}
CTime::~CTime()
{
	cout<<"析构函数被调用"<<endl; 
}
int CTime::dayDiff(CTime t)
{
	int sum0=0,sum=0,sum1=0,sum2=0,n,m,i;
	switch(month)
	{
		case 1:sum=day;break;
		case 2:sum=day+31;break;
		case 3:sum=day+59;break;
		case 4:sum=day+90;break;
		case 5:sum=day+120;break;
		case 6:sum=day+151;break;
		case 7:sum=day+181;break;
		case 8:sum=day+212;break;
		case 9:sum=day+243;break;
		case 10:sum=day+273;break;
		case 11:sum=day+304;break;
		case 12:sum=day+334;break;
		default:sum=0;break; 
	}
	if(month>2)
	{
		if((year%4==0&&year%100!=0)||(year%400==0))
		sum=sum+1;
	}
	switch(t.month)
	{
		case 1:sum2=t.day;break;
		case 2:sum2=t.day+31;break;
		case 3:sum2=t.day+59;break;
		case 4:sum2=t.day+90;break;
		case 5:sum2=t.day+120;break;
		case 6:sum2=t.day+151;break;
		case 7:sum2=t.day+181;break;
		case 8:sum2=t.day+212;break;
		case 9:sum2=t.day+243;break;
		case 10:sum2=t.day+273;break;
		case 11:sum2=t.day+304;break;
		case 12:sum2=t.day+334;break;
		default:sum2=0;break; 
	}
	if(t.month>2)
	{
		if((t.year%4==0&&t.year%100!=0)||(t.year%400==0))
		sum2=sum2+1;
	}
	if(year>t.year)
	{
		n=year;
		m=t.year;
	 } 
	else
	{
		m=year;
		n=t.year;
	}
	sum1=(n-m)*365;
	for(i=m;i<n;i++)
	{
		if((i%4==0&&i%100!=0)||(i%400==0))
		sum1+=1;
	}
	if(year<t.year&&sum>sum2)
	sum0=sum1-abs(sum-sum2);
	else if(t.year<year&&sum2>sum)
	sum0=sum1-abs(sum-sum2);
	else
	sum0=sum1+abs(sum-sum2);
	return sum0;
}
void CTime::showTime()
{
	cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":"<<minte<<":"<<second<<endl;
}
int CTime::isvalid()
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31},k,n;
	if((year%4==0&&year%100!=0)||(year%400==0))
	k=1;
	else
	k=0;
	if(k==1)
	a[1]=29;
	if(month>0&&month<=12&&day>0&&day<=31&&hour>=0&&hour<=23&&minte>=0&&minte<=59&&second>=0&&second<=59)
	{
		if(a[month-1]>=day)
		{
			n=1;
		}
		else
		{
			n=0;
		}
	}
	else
	n=0;
	return n;
}
int  main() 
{ 
        int year,month,day,hour,minute,second; 
        cin>>year>>month>>day>>hour>>minute>>second; 
        CTime t1(year,month,day,hour,minute,second); 
        t1.showTime(); 
        CTime t2(2000,1,1);  //利用默认形参将时间初始化为00:00:00 
        if(t1.isvalid())          //如果日期和时间合法，则计算天数 
        { 
            int days=0; 
            days=t1.dayDiff(t2); 
            cout<<"这两天之间相隔了"<<days<<"天"<<endl; 
            days=t2.dayDiff(t1); 
            cout<<"这两天之间相隔了"<<days<<"天"<<endl; 
        } 
}
