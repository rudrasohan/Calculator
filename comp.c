#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define max 200

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

int main(void)
{ 
  char x,ch;
  char post[max];
  int i=0;
  
  printf("Type the expression\n");
  //scanf("%[^/n]",infix);
  //printf("%s",infix);
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