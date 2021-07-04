#include<stdio.h>
int main()
{

	int i;
	char ch;
	printf("enter ASCII number or charecter: ");
	
	
	if(0>=1000000)
	{
           scanf("%d",&i);
           printf("ASCII charecter is: %c",i);
	}
	
	else if('a'>='z' || 'A'>='Z')
	{
	scanf("%c",&ch);
	printf("ASCII number is: %d",ch);	
	}
           
	return 0;
}
