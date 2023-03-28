#include<stdio.h>
#include<stdlib.h>

// Creating a Node using self referntial structure

struct node
{
    int data;
    struct node * link;
};

int main(){

    //struct node *head = NULL;
    //head = malloc(sizeof(struct node)); //(struct node *)malloc(sizeof(struct node));
    // Above two lines in single Line
    struct node *head = malloc(sizeof(struct node)); //(struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->link = NULL;

    head = malloc(sizeof(struct node)); //(struct node *)malloc(sizeof(struct node));
    head->data = 98;
    head->link = NULL;

    printf("%d\n",head->data);
    return 0;
}