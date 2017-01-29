/*
 Created By-
 ***********
  Sohan Rudra
  16MI10033
  L.B.S. Hall
*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define max 200

float result;
float result1;

float Result[100][100];
float a[100][100];
float b[100][100];

typedef struct{
float real;
float imag;
} COMPLEX;

COMPLEX C,r;

typedef struct stack {
    
    unsigned int st[max];
    int top;
}stack;


void create(stack*);
int isEmpty(stack*);
int isFull(stack*);
void push(stack*,char);
char pop(stack*);
int priority(char);
char topolem(stack*);
float eval(char x,float op1,float op2);

void create(stack *s)
{
    s->top = -1;
}

int isEmpty(stack *s)
{
    if(s->top == -1)
    return 1;
    else 
    return 0;
}

int isFull(stack *s)
{
    if(s->top == (max-1))
    return 1;
    else 
    return 0;
}

char pop(stack *s)
{
    if(isEmpty(s))
    {
        printf("Underflow ERROR");
        return -1;
        }
        char x;
        x = s->st[s->top];
        s->top = s->top -1;
        return x;
}

void push(stack *s,char ch)
{
     if(isFull(s))
    {
        printf("Overflow ERROR");
    }
    else
    {
        s->top = s->top + 1;
        s->st[s->top] = ch;
    }
}

char topolem(stack *s)
{
    return ( s->st[s->top]);
}

int priority(char x)
{
    if(x == '(')
    return 0;
    else if((x == '+')||(x == '-'))
    return 1;
    else if((x == '*')||(x == '/')||(x == '%'))
    return 2;
     else
    return 3;
}

float eval(char x,float op1,float op2)
{
    if(x == '+')
    return (op1+op2);
     if(x == '-')
    return (op1-op2);
     if(x == '*')
    return (op1*op2);
     if(x == '/')
    return (op1/op2);
    if(x == '^')
    return(pow(op1,op2));
    
    return -1;
}

COMPLEX add(COMPLEX A,COMPLEX B)
{
    C.real = A.real + B.real;
    C.imag = A.imag + B.imag;
    return C;
}

COMPLEX sub(COMPLEX A,COMPLEX B)
{
    C.real = A.real - B.real;
    C.imag = A.imag - B.imag;
    return C;
}

COMPLEX mult(COMPLEX A,COMPLEX B)
{
    C.real = (A.real*B.real)-(A.imag*B.imag);
    C.imag = (A.real*B.imag)+(A.imag*B.real);
    return C;
}

COMPLEX div(COMPLEX A,COMPLEX B)
{
    C.real = (A.real*B.real)+(A.imag*B.imag);
    C.imag = -(A.real*B.imag)+(A.imag*B.real);
    C.real = (C.real)/((B.real)*(B.real)+(B.imag)*(B.imag));
    C.imag = (C.imag)/((B.real)*(B.real)+(B.imag)*(B.imag));
    return C;
}

void polar(COMPLEX A)
{
    C.real = sqrt((A.real)*(A.real)+(A.imag)*(A.imag));
    C.imag = 180/3.141*acos(A.real/C.real);
    printf("Argument =%f\n",C.real);
    printf("Angle =%f\n",C.imag);
}

void comp()
{
     char x,ch;
  char post[max];
  int i=0;
  
  printf("\nType the expression\n");
//  scanf("%[^/n]",infix);
 // printf("%s",infix);
  stack s;
  create(&s);
  while((ch = getchar()) != '\n')
  {
      
      if(isalnum(ch)){
      printf("%c",ch);
      post[i++]=ch;
      }
      else
      {
          if(ch == '(')
          push(&s,'(');
          else
          {
              if(ch == ')')
              {
                  while((x=pop(&s)) != '(')
                  printf("%c",x);
                  post[i++] = x;
              }
              else
              {
                  while((!isEmpty(&s))&&(priority(ch) <= priority(topolem(&s))))
                  {
                      x = pop(&s);
                      printf("%c",x);
                      post[i++] = x;
                  }
                      push(&s,ch);
                  
              }
          }
      }
  }
  while(!isEmpty(&s))
  {
      x = pop(&s);
  printf("%c",x);
  post[i++] = x;
  }
  
  stack s1;
  
  float op1=0,op2=0;
float val = 0;
int c = i;
    for(i=0;i<c;i++)
    {
  // printf("%c",post[i]);
    }
    
    printf("\n");
    create(&s1);
    for(i = 0;i<c;i++)
    {
        x = post[i];
        if(isdigit(x))
        push(&s1,(x-48));
        else
        {
            op2 = pop(&s1);
            op1 =  pop(&s1);
            val = eval(x,op1,op2);
            push(&s1,val);
        }
    }
    val = pop(&s1);
    printf("Ans = %f",val);
    printf("\n");
}

void basic()
{
    char select,select1,dummy,dum,c;
    float num;
    printf("\n COMP Mode\n");
    printf("press _ to just enter\n");
    printf("press + to add\n");
    printf("press - to subtract\n");
    printf("press * to multiply\n");
    printf("press / to divide\n");
    printf("press a for sin(x)\n");
    printf("press b for cos(x)\n");
    printf("press c for tan(x)\n");
    printf("press d for asin(x)\n");
    printf("press e for acos(x)\n");
    printf("press f for atan(x)\n");
    printf("press g for sinh(x)\n");
    printf("press h for cosh(x)\n");
    printf("press i for tanh(x)\n");
    printf("press j for exp(x)\n");
    printf("press k for log(x)\n");
    printf("press l for log10(x)\n");
    printf("press m for pow(x,y)\n");
    printf("press n for sqrt(x)\n");
    printf("\nPress q to Quit\n");
    
    while(1)
    {
    	 printf("\nEnter the choice of function\n");
    	 scanf("%c",&dummy);
        scanf("%c",&select);
        if(select == 'q')
        break;
        printf("\nPress y to use the previous result or press n to give new value\n");
        scanf("%c",&c);
        scanf("%c",&dum);
        if(dum == 'y')
        num = result;
        else
        {
        printf("\nEnter the value\n");
        scanf("%f",&num);
        //scanf("%c",&c);
        }
       
        
        switch(select)
        {
        	case '_':
        		{
        			result1 = num;
        			printf("%f",result1);
        			break;
				}
            case 'a':
            {
                result1 = sin(num);
                printf("%f",result1);
                break;
            }
             case 'b':
            {
                result1 = cos(num);
           printf("%f",result1);
                break;
            }
             case 'c':
            {
                result1 = tan(num);
                 printf("%f",result1);
                break;
            }
             case 'd':
            {
                result1 = asin(num);
                 printf("%f",result1);
                break;
            }
             case 'e':
            {
                result1 = acos(num);
                 printf("%f",result1);
                break;
            }
             case 'f':
            {
                result1 = atan(num);
                 printf("%f",result1);
                break;
            }
             case 'g':
            {
                result1 = sinh(num);
                 printf("%f",result1);
                break;
            }
             case 'h':
            {
                result1 = cosh(num);
                 printf("%f",result1);
                break;
            }
             case 'i':
            {
                result1 = tanh(num);
                 printf("%f",result1);
                break;
            }
             case 'j':
            {
                result1 = exp(num);
                 printf("%f",result1);
                break;
            }
             case 'k':
            {
                result1 = log(num);
                 printf("%f",result1);
                break;
            }
             case 'l':
            {
                result1 = log10(num);
                 printf("%f",result1);
                break;
            }
             case 'm':
            {
                float y;
                printf("\nEnter the power\n");
                scanf("%f",&y);
                result1 = pow(num,y);
                 printf("%f",result1);
                break;
            }
            case 'n':
            {
                result1 = sqrt(num);
                 printf("%f",result1);
                break;
            }
        }
        
        printf("\nEnter the way by which you want to use this number in your result\n");
        scanf("%c",&c);
        scanf("%c",&select1);
        
        switch(select1)
        {
        	case '_' :
        		{
        			result = result1;
        			printf("%f\n",result);
        			break;
				}
		    case '+' :
		    	{
		    		result += result1;  
		    		printf("%f\n",result);
		    		break;
				}
				 case '-' :
		    	{
		    		result -= result1;  
		    		printf("%f\n",result);
		    		break;
				}
				 case '*' :
		    	{
		    		result *= result1;  
		    		printf("%f\n",result);
		    		break;
				}
				 case '/' :
		    	{
		    		result /= result1;  
		    		printf("%f\n",result);
		    		break;
				}
			
			
            case 'a':
            {
                result = sin(result1);
                printf("%f\n",result);
                break;
            }
             case 'b':
            {
                result = cos(result1);
           printf("%f\n",result);
                break;
            }
             case 'c':
            {
                result = tan(result1);
                 printf("%f\n",result);
                break;
            }
             case 'd':
            {
                result = asin(result1);
                 printf("%f\n",result);
                break;
            }
             case 'e':
            {
                result = acos(result1);
                 printf("%f\n",result);
                break;
            }
             case 'f':
            {
                result = atan(result1);
                 printf("%f\n",result);
                break;
            }
             case 'g':
            {
                result = sinh(result1);
                 printf("%f\n",result);
                break;
            }
             case 'h':
            {
                result = cosh(result1);
                 printf("%f\n",result);
                break;
            }
             case 'i':
            {
                result = tanh(result);
                 printf("%f\n",result);
                break;
            }
             case 'j':
            {
                result = exp(result1);
                 printf("%f\n",result);
                break;
            }
             case 'k':
            {
                result = log(result1);
                 printf("%f\n",result);
                break;
            }
             case 'l':
            {
                result = log10(result1);
                 printf("%f\n",result);
                break;
            }
             case 'm':
            {
                float y;
                printf("\nEnter the power\n");
                scanf("%f",&y);
                result= pow(result1,y);
                 printf("%f\n",result);
                break;
            }
            case 'n':
            {
                result = sqrt(result1);
                 printf("%f\n",result);
                break;
            }
        }
	}
}

void matrix()
{
    int m,n,i,j,flag = 1;
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 100; j++)
          {  Result[i][j] = 0;
             a[i][j] = 0;
             b[i][j] = 0;
          }
        }
    printf("\n MATRIX MODE\n");
    while(1)
    {
        int ch,k=0;
        
        if(flag == 1)
        {
              printf("\nEnter the number of rows and columns of the matrix\n");
                 scanf("%d%d", &m, &n);
                 printf("\nEnter the elements of first matrix\n");
 
                for (i = 0; i < m; i++)
                {
                    for (j = 0; j < n; j++)
                {
                    scanf("%f", &a[i][j]);
                    Result[i][j] = a[i][j];
                }
                }
                flag = 0;
        }
        printf("Enter 1 for addition\n");
        printf("Enter 2 for substraction\n");
        printf("Enter 3 for scalar multiplication\n");
        printf("Enter 4 for matrix multiplication\n");
        printf("\nEnter 5 to display result and quit\n");
        scanf("%d",&ch);
        printf("\n");
              
        
        
        if(ch == 5)
        {
           for (i = 0; i < m; i++) 
           {
           for (j = 0; j < n; j++)
           printf("%f\t", Result[i][j]);
 
           printf("\n");
           }
            break;
        }
        
        switch(ch)
        {
            case 1:
            {
                 
                 int p,q;
              printf("Enter the number of rows and columns of the matrix\n");
              scanf("%d%d", &p, &q);
 
              if ((m != p)||(n != q))
              printf("\nMatrices with entered orders are not compatible with each other.\n");
                   
               else 
                {
                     printf("\nEnter the elements of the matrix\n");
 
                 for (i = 0; i < p; i++)
                 for (j = 0; j < q; j++)
                 scanf("%f", &b[i][j]);
                
                for (i = 0; i < m; i++)
                for (j = 0; j < n; j++)
                Result[i][j] = Result[i][j] +b[i][j];
                }
                break;
            }
            case 2:
                
                {
                    
                int p,q;
              printf("Enter the number of rows and columns of the matrix\n");
              scanf("%d%d", &p, &q);
 
              if ((m != p)||(n != q))
              printf("\nMatrices with entered orders are not compatible with each other.\n");
                else
                {
                    
                 printf("Enter the elements of the matrix\n");
 
                 for (i = 0; i < p; i++)
                 for (j = 0; j < q; j++)
                 scanf("%f", &b[i][j]);
                 
                for (i = 0; i < m; i++)
                for (j = 0; j < n; j++)
                Result[i][j] = Result[i][j]  - b[i][j];
                }
                break;
            }
            case 3:
                
                {
                    
               
                float K = 0.0;
                printf("Enter the factor\n");
                  scanf("%f",&K); 

                for (i = 0; i < m; i++)
                for (j = 0; j < n; j++)
                Result[i][j] = K * Result[i][j];
                
                break;
            }
            case 4:
                
                {
                    
             
              int p,q;
              printf("Enter the number of rows and columns of the matrix\n");
              scanf("%d%d", &p, &q);
 
              if (n != p)
              printf("Matrices with entered orders can't be multiplied with each other.\n");
              
              else
              {
                     for (i = 0; i < m; i++)
                {
                    for (j = 0; j < n; j++)
                {
                    a[i][j] = Result[i][j];
                    Result[i][j] = 0;
                }
                }
                 printf("Enter the elements of the matrix\n");
 
                 for (i = 0; i < p; i++)
                 for (j = 0; j < q; j++)
                 scanf("%f", &b[i][j]);
 
                for (i = 0; i < m; i++)
                {
                for (j = 0; j < q; j++)
                {
                for (k = 0; k < p; k++)
                {
                  Result[i][j] = Result[i][j] + a[i][k]*b[k][j];
                }
                    
                }
                    
                }
                
                n = q;
                 break;
            }
        }
        
    }
}

}

void complex()
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
        
        r.real = 0;
        r.imag = 0;
        
    
        printf("Enter a complex number \n");
        printf("Enter the real part then the complex part\n");
        scanf("%f%f",&r.real,&r.imag);
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
                     c1 = add(r,temp);
                     r = c1;
                    break;
                }
                case 2:
                {
                     printf("Enter another complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp.real,&temp.imag);
                     printf("\n");
                     c1 = sub(r,temp);
                     r = c1;
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
                     c1 = mult(r,temp);
                     r = c1;
                    }
                    else
                    {
                     printf("Enter the second complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp1.real,&temp1.imag);
                     printf("\n");   
                     c1 = mult(temp1,temp);
                     r.real += c1.real;
                     r.imag += c1.imag;
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
                     c1 = div(r,temp);
                     r = c1;
                    }
                    else
                    {
                        
                     printf("Enter the second complex number \n");
                     printf("Enter the real part then the complex part\n");
                     scanf("%f%f",&temp1.real,&temp1.imag);
                     printf("\n");   
                     c1 = div(temp,temp1);
                     r.real += c1.real;
                     r.imag += c1.imag;
                    }
                    break;
                }
                case 5:
                {
                    polar(r);
                    break;
                }
                case 6:
                {
                    printf("\n%f +%fi\n",r.real,r.imag);
                }
            }
        }
}

int main(void)
{
       int CH;
        char c;
        while(1)
        { 
        printf("Enter 1 for quick single digit expression evaluation\n");
        printf("Enter 2 for basic Calculator\n");
        printf("Enter 3 for matrix Calculator\n");
        printf("Enter 4 for complex Calculator\n");
        printf("Enter 5 to quit\n");
        
        scanf("%d",&CH);
        
        if(CH == 5)
        break;
        
            switch(CH)
            {
                case 1:
                {
                    scanf("%c",&c);
                    comp();
                    break;
                }
                case 2:
                {
                    basic();
                    break;
                }
                case 3:
                {
                    matrix();
                    break;
                }
                case 4:
                {
                    complex();
                    break;
                }
            }
        }
        
}