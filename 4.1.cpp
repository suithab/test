#include<iostream> 
#include<cstring> 
using namespace std; 
int cmpGT(const int *p1,const int *p2) 
{ 
//ʵ�������Ƚϣ�������ڣ��򷵻�1�������򷵻�0��С���򷵻�-1 
 if(*p1>*p2)
 return 1;
 else if(*p1==*p2)
 return 0;
 else
 return -1; 
} 
int cmpLT(const int *p1,const int *p2) 
{ 
//ʵ�������Ƚϣ�������ڣ��򷵻�-1�������򷵻�0��С���򷵻�1 
 if(*p2>*p1)
 return 1;
 else if(*p1==*p2)
 return 0;
 else
 return -1; 
} 
void swap(int *p1,int *p2) 
{ 
//ʵ���������α�����ֵ���� 
 int p;
 p=*p1;
 *p1=*p2;
 *p2=p;
} 
void bubble(int *base,int(*cmp)(const int *,const int *)) 
{ 
//�������ﲹ��ð�����������main�����ж�bubble�����ĵ��ã������βε����� 
 int *a;
 int i,j,t;
 a=base;
 for(i=0;i<10;i++)
 {
 	for(j=0;j<9-i;j++)
 	{
 		if((*cmp)((a+j),(a+j+1))==1)
 		{
 			swap(a+j,a+j+1);
		}
 	}
 }

} 
int main() 
{ 
    int arr[]={1,3,5,7,9,2,4,6,8,0}; 
    int i=0; 
    bubble(arr,cmpGT); 
    for(i=0;i<10;i++) 
    { 
        cout<<arr[i]<<"  "; 
    } 
    cout<<endl; 
    bubble(arr,cmpLT); 
    for(i=0;i<10;i++) 
    { 
        cout<<arr[i]<<"  "; 
    }         
    cout<<endl; 
    return 0; 
}