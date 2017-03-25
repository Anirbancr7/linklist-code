#include <stdio.h>
#include <stdlib.h>


typedef struct s{
                   int data;
                   int *left;
                   int *right;
                }node;

main()
{
   node *root=NULL;
   int choice,data;
   while(1)
   {
       printf("1.\nInsertion\n2.Pre-order\n3.Post-order\n4.In-order\n5.Non recursive preorder\n6.Non recursive inorder\n7.Exit\nEnter your choice:\n");
       scanf("%d",&choice);
       switch(choice)
         {
            case 1:  printf("Enter data:\n");
                     scanf("%d",&data);
                     insert(&root,data);
                     break;
            case 2:  preorder(root);
                     break;
            case 3:  postorder(root);
                     break;
            case 4:  inorder(root);
                     break;
            case 5:  nonrecpre(root);
                     break;
            case 6:  nonrecin(root);
                      break;
            case 7:  exit(0);
                     break;

         }
     }
}


void insert(node **ptr,int data)
{
   node *newnode,*temp;
   newnode=(node *)malloc(sizeof(node));
   newnode->data=data;
   newnode->left=NULL;
   newnode->right=NULL;

   if(*ptr==NULL)
    {
       *ptr=newnode;
       return;
     }
    temp=*ptr;
    while(1)
    {
       if(data<temp->data)
       {
          if(temp->left==NULL)
          {
              temp->left=newnode;
              break;
           }
           temp=temp->left;
        }
        else
        {


              if(temp->right==NULL)
              {
                 temp->right=newnode;
                 break;
               }
               temp=temp->right;
           }
         }
      }



 void preorder(node *p )

 {
    if(p!=NULL)
    {

     printf("%4d",p->data);
     preorder(p->left);
     preorder(p->right);
 }}

 void inorder(node *p )

 {
   if(p!=NULL)
   {
     inorder(p->left);
     printf("%4d",p->data);

     inorder(p->right);
 }}

 void postorder(node *p )

 {
     if(p!=NULL)
     {
     postorder(p->left);
     postorder(p->right);
     printf("%4d",p->data);
 }}


void nonrecpre(node *ptr)
{
  node *stack[10];
  int top=-1;
  while(1)
  {
     while(ptr!=NULL)
     {
        printf("%4d",ptr->data);
        stack[++top]=ptr;
        ptr=ptr->left;
     }
      if(top==-1)
      return;
     ptr=stack[top--];
     ptr=ptr->right;


  }

}

nonrecin(node *ptr)
{
  node *stack[10];
  int top=-1;
  while(1)
  {
     while(ptr!=NULL)
     {
        stack[++top]=ptr;
        ptr=ptr->left;
      }
      if(top==-1)
      return;
     ptr=stack[top--];
     printf("%4d",ptr->data);
     ptr=ptr->right;
   }

}













