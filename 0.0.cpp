#include  <iostream> 
#include<iomanip> 
using  namespace  std; 
void  swap1(float  *a,  float  *b) 
{
int c;
c=*a;*a=*b;*b=c;
} 
void  swap2(float  &a,  float  &b) 
{ 
float *p=&a,*q=&b,c;
c=*p;*p=*q;*q=c;
} 
int  main() 
{ 
        float  m,n; 
        cin>>m>>n; 
        swap1(&m,&n); 
        cout<<fixed<<setprecision(2)<<m<<"  "<<n<<endl; 
        swap2(m,n); 
        cout<<fixed<<setprecision(2)<<m<<"  "<<n<<endl; 
        cin>>m; 
} 
