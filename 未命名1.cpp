#include  <iostream> 
#include  <cmath> 
using  namespace  std; 

//�ж��Ƿ�Ϊ���� 
int  isPrime(long  num) 
{ 
	int i,k;
for(i=2;i<num;i++)
{   if( num%i==0)
    break;
}
if(i>=num)
return 1;
else 
return 0;
} 
//���������طֽ⣬ 
void  factorization(long n, long b[ ],int &a) 
{ 
	int i,k=0;
	int *c=&a;
	for(i=2;i<=n;)
	{
		if(isPrime(i))
		{
			if(n==i)
			{
				b[k]=n;
				(*c)++;
				break;
			}
			else if(n%i==0)
			{
				b[k]=i;
				k++;
				n/=i;
				(*c)++;	
			}
			else
			i++;
		}
		else
		i++;
	} 
} 
int main() 
{ 
        long n; 
        long factor[100]; 
        int numofFactor=0; 
        cin>>n; 
        factorization(n,factor,numofFactor); 
        for  (int i=0;i<numofFactor;i++) 
        { 
            cout<<factor[i]<<" "; 
        } 
        cout<<endl; 
        return  0; 
} 
