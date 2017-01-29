#include <stdio.h>
#include <math.h>

typedef struct{
float real;
float imag;
} COMPLEX;

COMPLEX c,result;

COMPLEX add(COMPLEX a,COMPLEX b)
{
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

COMPLEX sub(COMPLEX a,COMPLEX b)
{
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

COMPLEX mult(COMPLEX a,COMPLEX b)
{
    c.real = (a.real*b.real)-(a.imag*b.imag);
    c.imag = (a.real*b.imag)+(a.imag*b.real);
    return c;
}

COMPLEX div(COMPLEX a,COMPLEX b)
{
    c.real = (a.real*b.real)+(a.imag*b.imag);
    c.imag = -(a.real*b.imag)+(a.imag*b.real);
    c.real = (c.real)/((b.real)*(b.real)+(b.imag)*(b.imag));
    c.imag = (c.imag)/((b.real)*(b.real)+(b.imag)*(b.imag));
    return c;
}

void polar(COMPLEX a)
{
    c.real = sqrt((a.real)*(a.real)+(a.imag)*(a.imag));
    c.imag = 180/3.141*acos(a.real/c.real);
    printf("Argument =%f\n",c.real);
    printf("Angle =%f\n",c.imag);
}

int main(void)
{
    int ch;
    char choice,dummy;
    COMPLEX temp,temp1,c1;
        printf("Enter 1 for addition\n");
        printf("Enter 2 for substraction\n");
        printf("Enter 3 for multiplication\n");
        printf("Enter 4 for division\n");
        printf("Enter 5 to see polar equivalent\n");
        printf("Enter 6 to see a + ib representation\n");
        printf("\nEnter 7 to quit\n");
        
        result.real = 0;
        result.imag = 0;
        
    
        printf("Enter a complex number \n");
        printf("Enter the real part then the complex part\n");
        scanf("%f%f",&result.real,&result.imag);
        printf("\n");
        
       
        while(1)
        {
            printf("\nEnter choice - \n");
            scanf("%d",&ch);
            if(ch == 7)
            break;
            switch(ch)
            {
                case 1:
                {
                     printf("Enter another complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp.real,&temp.imag);
                     printf("\n");
                     c1 = add(result,temp);
                     result = c1;
                    break;
                }
                case 2:
                {
                     printf("Enter another complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp.real,&temp.imag);
                     printf("\n");
                     c1 = sub(result,temp);
                     result = c1;
                     break;
                }
                case 3:
                {
                    printf(" Enter Y to multiply two different complex number and N to multiply with the result\n");
                    scanf("%c",&dummy);
                    scanf("%c",&choice);
                     printf("Enter a complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp.real,&temp.imag);
                     printf("\n"); 
                    if(choice == 'N')
                    {
                     c1 = mult(result,temp);
                     result = c1;
                    }
                    else
                    {
                     printf("Enter the second complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp1.real,&temp1.imag);
                     printf("\n");   
                     c1 = mult(temp1,temp);
                     result.real += c1.real;
                     result.imag += c1.imag;
                    }
                    break;
                }
                case 4:
                { printf(" Enter Y to divide two different complex number and N to devide with the result\n");
                    printf("\nIn case Y -> The second number will be the denominator \n");
                    scanf("%c",&dummy);
                    scanf("%c",&choice);
                     printf("Enter a complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp.real,&temp.imag);
                     printf("\n"); 
                    if(choice == 'N')
                    {
                     c1 = div(result,temp);
                     result = c1;
                    }
                    else
                    {
                        
                     printf("Enter the second complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp1.real,&temp1.imag);
                     printf("\n");   
                     c1 = div(temp,temp1);
                     result.real += c1.real;
                     result.imag += c1.imag;
                    }
                    break;
                }
                case 5:
                {
                    polar(result);
                    break;
                }
                case 6:
                {
                    printf("\n%f +%fi\n",result.real,result.imag);
                }
            }
        }
}