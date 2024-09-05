// Pointers
// Pointer is a address variable that stores the address of variable or data
// Declaration
// Intilaization
// Derefercing
// Dynamic memory allocation

// Pointers are used for accessing the Heap memory, resources outside the program 
//(Display, Keyboard, files, other resources) and passing the varaibles to functions.


#include<iostream>
using namespace std;   
#include<stdio.h>


int main()
{
    int a=10;
    int *p; // declaration
    p=&a; // intializtion with value
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl; // Derefernce for accessing the value

    int *ptr; // whenever we declare the var its take resources from stack and then
            // how to allocate the memory in heap we can do by using new keyword using malloc()
    ptr = (int *) malloc(5*sizeof(int));  // holding the starting address of the Heap mem

    //ptr =new int[5] // in c++ we can do this
     

}