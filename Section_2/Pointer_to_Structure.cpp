// Pointer to Struture

#include<iostream>
using namespace std;
#include<stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    // using pointer in stack
    struct Rectangle r={10,5}; 
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
    struct Rectangle *p = &r; 


    printf("%d\n",p->length);
    printf("%d\n",p->breadth);


    // using pointer in heap
    struct Rectangle *ptr; // inside c++ Rectangle *ptr is sucffcient
    ptr = (struct Rectangle *) malloc(sizeof(struct Rectangle)); // in c
    //ptr = new Rectangle; in c++
    ptr->length = 10; 
    ptr->breadth = 5;
    cout<<ptr->length<<endl;
    cout<<ptr->breadth<<endl;
    printf("%d\n",ptr->length);
    printf("%d\n",ptr->breadth);
    return 0;
}