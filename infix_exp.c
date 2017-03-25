#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 10
typedef struct s{
                   int a[50];
                   int top;
                }stack;

void push(stack*,int);
int pop(stack*);



int main()
{
    stack s;
    s.top=-1;
    char array[50];
    int i=0;
    float op1,op2,op3,result;
    printf("Enter the postfix expression:\n");
    gets(array);
    while(array[i]!='\0')
    {
      if(isdigit(array[i]))
        push(&s,array[i]-'0');
      else
       {
          op1=pop(&s);
          op2=pop(&s);
          switch(array[i])
          {
            case '+': op3=op2+op1;
                       break;
            case '-': op3=op2-op1;
                       break;
            case '*': op3=op2*op1;
                       break;
            case '/': op3=op2/op1;
                       break;
           }
          push(&s,op3);
        }
        i++;
      }
      result=pop(&s);
      printf("The result is:%f",result);
      return 0;
 }


void push(stack *p,int data)
{
  if(p->top==MAX-1)
   {
     printf("Stack is full");
     return;
     }

     (p->top)++;
     p->a[p->top]=data;
}

int pop(stack*p)
{
  int n;
   if(p->top==-1)
     {
       printf("Stack is empty");
       return -1;
       }

       n=p->a[p->top];

       (p->top)--;

       return n;
}
