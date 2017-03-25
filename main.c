#include <stdio.h>
#include <stdlib.h>

typedef struct s{
                  int data;
                   struct s *link;
                }node;
 main()
 {
   int data,choice;
   node *s1;

   while(1)
   {
     choice=menu();
     switch(choice)
      {
        case 1:
               insertend(&s1);
               break;
        case 2:
               insertbeg(&s1);
               break;
        case 3:deleteend(&s1);
                break;
        case 4:deletebeg(&s1);
               break;

        case 5:insertbypos(&s1);
               break;
        case 6:deletebypos(&s1);
               break;
        case 7:display(&s1);
                break;
        case 8: exit(0);
                break;
      }
     }
   }

   void insertend(node **p)
   {
      node *s1,*s2;
      int n,data,i;
      printf("How many nodes?");
      scanf("%d",&n);
      s1=(node *)malloc(sizeof(node));
      printf("Enter data: \n");
      scanf("%d",&s1->data);

      s1->link=NULL;
      for(i=2;i<=n;i++)
       {
         s2=(node *)malloc(sizeof(node));
         printf("enter data:\n");
         scanf("%d",&s2->data);
         s2->link=NULL;
         s1->link=s2;
         s1=s2;
       }
    }

   void insertbeg(node **p)
    {
        int data;
        node *s3;
        s3=(node *)malloc(sizeof(node));
        printf("Enter data;\n");
        scanf("%d",&s3->data);
        s3->link=*p;
    }

   void deletebeg(node **p)
   {
     node *temp;
     if(*p==NULL)
       {
       printf("List empty!\n");
       return;
       }
      temp=*p;
      *p=(*p)->link;
      free(temp);

   }

   void deleteend(node **p)
   {
     node *d1,*s;
     s=*p;
     while(s!=NULL)
     {
       d1=s;
       s=s->link;
     }
    d1->link=s->link;
     free(s);
   }

  void insertbypos(node **p)
  {
    int i,n;
    node *s4,*s1,*d1;
    s1=*p;
    s4=(node *)malloc(sizeof(node));
    printf("Enter the position to be entered:\n");
    scanf("%d",&i);
    printf("Enter data:\n");
    scanf("%d",&s4->data);
    s4->link=NULL;
    for(n=0;n<i;n++)
    {
          d1=s1;
          s1=s1->link;
     }
    d1->link=s4;
    s4->link=s1;
   }
  void deletebypos(node **p)
  {
    int i,n;
    node *d2,*s1;
    s1=*p;
    printf("Enter the position to be deleted\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
     {
        d2=s1;
        s1=s1->link;
      }
     d2->link=s1->link;
     printf("the data deleted is: %d\n",s1->data);
     free(s1);
   }
  int menu()
  {
     int ch;
     printf("1.Insert end\n2.Insert beginning\n3.Delete from end\n4.Delete from beginnning\n5.Insert by pos\n6.Delete by pos\n7.Display\n8.Exit\n");
    scanf("%d",&ch);
    return ch;

  }

  void display(node *p)
  {

    while(p!=NULL)
    {

       printf("%d",p->data);
       p=p->link;
     }
    printf("NULL");
  }















