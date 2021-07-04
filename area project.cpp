#include<stdio.h>

int main() {

    char character;
    float radius,Carea;
    float height,width,Rarea;
    float base,height1,Tarea;
    float height2,Sarea;

    printf("                                            ******* Choice 1 Option *******\n");
    printf("1.Press C to Find The Area of The Circle.\n");
    printf("2.Press R to Find The Area of The Rectangle.\n");
    printf("3.Press T to Find The Area of The Triangle.\n");
    printf("4.Press S to Find the Area of The Square.\n");

    scanf("%c", &character);


    switch(character)
    {
        case 'C':
            printf("Enter the Radius Of The Circle:");
            scanf("%f",&radius);
            Carea=3.1416*radius*radius;
            printf("The Area of The Circle is:%f",Carea);
            break;

        case 'c':
            printf("Enter The Radius Of The Circle:");
            scanf("%f",&radius);
            Carea=3.1416*radius*radius;
            printf("The Area of The Circle is:%f",Carea);
            break;

        case 'R':
            printf("Enter The Height of The Rectangle:");
            scanf("%f",&height);
            printf("Enter the Width of The Rectangle:");
            scanf("%f",&width);
            Rarea=height*width;
            printf("The Area of the Rectangle is:%f",Rarea);
            break;

        case 'r':
             printf("Enter The Height of the Rectangle:");
            scanf("%f",&height);
            printf("Enter The Width of The Rectangle:");
            scanf("%f",&width);
            Rarea=height*width;
            printf("The Area of The Rectangle is:%f",Rarea);
            break;

        case 'T':
             printf("Enter the base of the Triangle:");
            scanf("%f",&base);
            printf("Enter the height of the Rectangle:");
            scanf("%f",&height1);
            Tarea=(1/2)*base*height1;
            printf("The Area of the Triangle is:%f",Tarea);
            break;

        case 't':
             printf("Enter the base of the Triangle:");
            scanf("%f",&base);
            printf("Enter the height of the Rectangle:");
            scanf("%f",&height1);
            Tarea=0.5*base*height1;
            printf("The Area of the Triangle is:%f",Tarea);
            break;

        case 'S':
            printf("Enter the height of the Square:");
            scanf("%f",&height2);
            Sarea=height2*height2;
            printf("The Area of the Square is:%f",Sarea);
            break;

        case 's':
            printf("Enter the height of the Square:");
            scanf("%f",&height2);
            Sarea=height2*height2;
            printf("The Area of the Square is:%f",Sarea);
            break;

        default:
            printf("Error! Character is not correct");
    }

    return 0;
}


