#include <stdio.h>
#include <math.h>

float result[100][100];
float a[100][100];
float b[100][100];


int main(void)
{
    int m,n,i,j,flag = 1;
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 100; j++)
          {  result[i][j] = 0;
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
                    result[i][j] = a[i][j];
                }
                }
                flag = 0;
        }
        printf("Enter 1 for addition\n");
        printf("Enter 2 for substraction\n");
        printf("Enter 3 for scalar multiplication\n");
        printf("Enter 4 for matrix multiplication\n");
        printf("\nEnter 5 to display result\n");
        scanf("%d",&ch);
        printf("\n");
              
        
        
        if(ch == 5)
        {
           for (i = 0; i < m; i++) 
           {
           for (j = 0; j < n; j++)
           printf("%f\t", result[i][j]);
 
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
                result[i][j] = result[i][j] +b[i][j];
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
                result[i][j] = result[i][j]  - b[i][j];
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
                result[i][j] = K * result[i][j];
                
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
                    a[i][j] = result[i][j];
                    result[i][j] = 0;
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
                  result[i][j] = result[i][j] + a[i][k]*b[k][j];
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