#include <stdio.h>
#include <math.h>

float result;
float result1;
int main(void)
{
    char select,select1,c;
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
        scanf("%c",&select);
        if(select == 'q')
        break;
        printf("\nEnter the number or press 1 to use the previous result\n");
        scanf("%f",&num);
        scanf("%c",&c);
        
        if(num == 1)
        num=result;
        
        switch(select)
        {
        	case '_':
        		{
        			result1 = num;
        			break;
				}
            case 'a':
            {
                result1 = sin(num);
                printf("%f",result);
                break;
            }
             case 'b':
            {
                result1 = cos(num);
           printf("%f",result);
                break;
            }
             case 'c':
            {
                result1 = tan(num);
                 printf("%f",result);
                break;
            }
             case 'd':
            {
                result1 = asin(num);
                 printf("%f",result);
                break;
            }
             case 'e':
            {
                result1 = acos(num);
                 printf("%f",result);
                break;
            }
             case 'f':
            {
                result1 = atan(num);
                 printf("%f",result);
                break;
            }
             case 'g':
            {
                result1 = sinh(num);
                 printf("%f",result);
                break;
            }
             case 'h':
            {
                result1 = cosh(num);
                 printf("%f",result);
                break;
            }
             case 'i':
            {
                result1 = tanh(num);
                 printf("%f",result);
                break;
            }
             case 'j':
            {
                result1 = exp(num);
                 printf("%f",result);
                break;
            }
             case 'k':
            {
                result1 = log(num);
                 printf("%f",result);
                break;
            }
             case 'l':
            {
                result1 = log10(num);
                 printf("%f",result);
                break;
            }
             case 'm':
            {
                float y;
                printf("\nEnter the power\n");
                scanf("%f",&y);
                result1 = pow(num,y);
                 printf("%f",result);
                break;
            }
            case 'n':
            {
                result1 = sqrt(num);
                 printf("%f",result);
                break;
            }
        }
        
        printf("\nEnter the way by which you want to use this number in your result\n");
        scanf("%c",&select1);
        scanf("%c",&c);
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
