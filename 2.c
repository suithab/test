#include<stdio.h>
int main()
{
	int a[10],sum=0,i,high;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	scanf("%d",&high);
	for(i=0;i<10;i++)
	{
		if(a[i]<=(high+30))
		sum++; 
	}
	printf("%d",sum);
	return 0; 
 } 
