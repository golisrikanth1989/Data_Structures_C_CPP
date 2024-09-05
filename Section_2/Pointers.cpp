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
#include<stdlib.h>


int main()
{
    int a=10; 
    int *p; // declaration use *
    p=&a; // intializtion with value don't use *
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<&a<<endl;
    
    cout<<*p<<endl; // Derefernce for accessing the value again use *

    
    int A[5] ={2,3,4,5,6};
    int *pA;
    pA = A; //pA=&A[0] // don't use pA = &A

    for (int i=0;i<5;i++)
    {
        cout<<A[i]<<endl;
        cout<<pA[i]<<endl;
        
    }
    
    
    int *ptr; // whenever we declare the var its take resources from stack and then
            // how to allocate the memory in heap we can do by using new keyword using malloc()
    ptr = (int *) malloc(5*sizeof(int));  // holding the starting address of the Heap mem

    //ptr =new int[5] // in c++ we can do this
    ptr[0]=11; ptr[1]=15;ptr[2]=20;ptr[3]=25;ptr[4]=30;
    for (int i=0;i<5;i++)
    {
        cout<<ptr[i]<<endl;
        
    }

    free(ptr); // release the memory in heap

    int *ptr1; // whenever we declare the var its take resources from stack and then
            // how to allocate the memory in heap we can do by using new keyword using malloc()
    //ptr1 = (int *) malloc(5*sizeof(int));  // holding the starting address of the Heap mem

    ptr1 =new int[5]; // in c++ we can do this
    ptr1[0]=11; ptr1[1]=15;ptr1[2]=20;ptr1[3]=25;ptr1[4]=30;
    for (int i=0;i<5;i++)
    {
        cout<<ptr1[i]<<endl;
        
    }

    delete [] ptr1; // release the memory in heap



    int *p1;
    char *p2;
    float *p3;
    double *p4;
    long *p5;
    short *p6;
    long long *p7;
    long double *p8;
    bool *p9;
    void *p10;
    // size of pointer is independent of the data type
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;
    cout<<sizeof(p6)<<endl;
    cout<<sizeof(p7)<<endl;
    cout<<sizeof(p8)<<endl;
    cout<<sizeof(p9)<<endl;
    cout<<sizeof(p10)<<endl;

    return 0;


}