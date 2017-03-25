#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
typedef struct s{
                   char arr[MAX];
                   int top;
                }stack;

char pop();
int precedence(char);
char topofstack();

char infix[100],postfix[100];
stack st;

main()
{
   st.top=-1;
   int v=0,i=0,j=0,v1=0;
   char ch;
   printf("Enter your infix expression\n");
   gets(infix);
   push('(');
   v=strlen(infix);
   infix[v]=')';
   infix[v+1]='\0';

   for(i=0;infix[i]!='\0';i++)
   {
      if(isalpha(infix[i]))
       {
           postfix[j+1]=infix[i];
        }
       else if(infix[i]=='(')
        {
           while((ch=pop())!='(')
             postfix[j+1]=ch;
         }
       else
        v=precedence(infix[i]);
        ch=topofstack();
        v1=precedence(ch);
        if(v>v1)
          push(infix[i]);
        else
         {
           while(v1>=v)
             {
                ch=pop();
                postfix[j+1]=ch;
                ch=topofstack();
                v1=precedence(ch);
              }
             push(infix[i]);
          }

    }
    puts(postfix);
  }
  void push(char item)
  {
    if(st.top==MAX-1)
    {
      printf("Stack full\n");
      return;
     }
    (st.top)++;
    st.arr[st.top]=item;
  }

  char pop()
  {
    char ch;
    if(st.top==-1)
     {
        printf("Stack is empty\n");
        return -99;
      }

      ch=st.arr[st.top];
      st.top--;
      return ch;
   }

   int precedence(char ch)
   {
     switch(ch)
      {
         case '^' :return 5;
         case '/' :
         case '*' :return 4;
         case '+' :
         case '-' :return 3;
         default  :return 0;
       }
   }

   char topofstack()
   {
   return st.arr[st.top];
   }
