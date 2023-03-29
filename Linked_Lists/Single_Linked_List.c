#include<stdio.h>
#include<stdlib.h>

// Creating a Node using self referntial structure

struct node
{
    int data;
    struct node * link;
};


void inserStart(struct node **head, int data)
{
    // Dynamically create a memory for this newNode
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    
    //Assign the data value
    newNode->data=data;
    // Change the next node of this newNode
    // to current head of the Linked List
    newNode->link = *head;

    // changing the new head to this freshly entered node
    *head = newNode;
    printf("\n%d Inserted\n",newNode-data);
}

void count(struct node *head)
{
  int count = 0;
  if(head == NULL)
  {
    printf("Linked List is Empty");
  }
  struct node *ptr = NULL;
  ptr = head;
  while (ptr!=NULL)
  {
    count++;
    ptr = ptr->link;
  }
  printf("%d\n",count); 
}

void Display(struct node *head)
{
  if(head == NULL)
  {
    printf("Linked List is Empty");
  }
  struct node *ptr = NULL;
  ptr = head;
  while (ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr = ptr->link;
  } 
}

struct node* Insert_Begin_Optimal(struct node *ptr, int data)
{
   struct node *temp = (struct node*) malloc(sizeof(struct node));

   temp->data = data;
   temp->link = NULL;

   ptr->link=temp;
   return temp;
}


void Insert_End(struct node *head, int data)
{
   struct node *ptr, *temp;
   ptr = head;
   temp = (struct node*) malloc(sizeof(struct node));

   temp->data = data;
   temp->link = NULL;

   while(ptr->link!=NULL)
   {
    ptr=ptr->link;
   }
   ptr->link=temp;
}



int main(){

    //struct node *head = NULL;
    //head = malloc(sizeof(struct node)); //(struct node *)malloc(sizeof(struct node));
    // Above two lines in single Line
    struct node *head = malloc(sizeof(struct node)); //(struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node)); //(struct node *)malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current; 
    printf("%d\n",head->data);
    printf("%d\n",current->data);


    Insert_End(head,47);
    
    // Optimal way
    struct node *ptr = head;
    ptr = Insert_End_Optimal(ptr,76);
    

    ptr = head;

    
    return 0;
}