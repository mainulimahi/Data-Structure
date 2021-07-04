#include<stdio.h>
int main()
{

	int i,n,t1=0,t2=1,nextTerm;
	
	printf("Enter no of terms you want: ");
	scanf("%d",&n);
	
	printf("the fibonacci series is: ");
	
	for(i=1;i<=n;i++)
	{
	printf("%d",t1);
	nextTerm=t1+t2;
	t1=t2;
	t2=nextTerm;	
	}
		
	return 0;
}
