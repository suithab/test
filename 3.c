#include<stdio.h>
#include<stdlib.h>  
int main()
{
    FILE *fp;
    int a=0,sum=0,sum1=0;
    if((fp=fopen("file11_1.txt","r"))==NULL)
    {
    	printf("Cannot open file strike any key exit!");
        exit(1);
    }
    while(!feof(fp))
    {
    	fscanf(fp,"%d",&a);
    	if(a<0)
    	sum=sum+a;
    	if(a>0)
    	sum1=sum1+a;
	}
    printf("sum>0 number is %d,sum<0 number is %d",sum1,sum);
    fclose(fp);
    return 0;
} 
