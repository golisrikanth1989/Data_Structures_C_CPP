// Structures are used for representing data with differnt 
// primitive data types as used defined datatypes

// In this we learn about
// 1. Defining Structure
// 2. Accessing Structure
// 3. Declaring the Structure
// 4. Size of Structure

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;

}r1;
// Defining Structure never consumes memory until it is initilized in the program

// this is better used to represent complex numbers in signal processing
// Dot opertaor is used in accessing the structure elements
struct Complex
{
    int Real;
    int Imaginary;

} c1,c2;  // Decalring and intilaization at the same time

struct Student
{
    int Roll;
    char Name[30];
    char Department[10];
    char Address[100];

};




// Inside the structures padding of memory is done automatically based on the compiler 
// it is deided based on the maximum size of the data type used in the structure
int main()
{
    struct Rectangle r;
    r.length = 10;
    r.breadth = 5;
    cout<<sizeof(r)<<endl;
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
    printf("%d\n",r.length);
    printf("%d\n",r.breadth);

    struct Rectangle r1={8,6};
    cout<<sizeof(r1)<<endl;
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;
    printf("%d\n",r1.length);
    printf("%d\n",r1.breadth);
    
    return 0;

}