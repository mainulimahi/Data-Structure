#include<stdio.h>
int main(){
	
	float mark;
	
	printf("enter your mark: ");
	scanf("%f",&mark);
	
	if(mark>=80 && mark<=100)
	printf("your marks is %.2f grade A+ and point 5.00",mark);
	
	else if(mark>=70 && mark<=79)
	printf("your marks is %.2f grade A and point 4.00",mark);
	
	else if(mark>=60 && mark<=69)
	printf("your marks is %.2f grade A- and point 3.50",mark);
	
	else if(mark>=50 && mark<=59)
	printf("your marks is %.2f grade B and point 3.00",mark);
	
	else if(mark>=40 && mark<=49)
	printf("your marks is %.2f grade C and point 2.50",mark);
	
	else if(mark>=33 && mark<=39)
	printf("your marks is %.2f grade D and point 2.00",mark);
	
	else if(mark>=0 && mark<=32)
	printf("your marks is %.2f grade F and point 0.00",mark);
	
	else
	printf("you entered an invalid number");
	
	
	return 0;
}
