// Reference
// Reference is a variable that stores the value of other varaible
// or Another name to variable 
// why do we need reference? this is used for parameter passing

#include<iostream>
#include<stdio.h>


using namespace std;


int main()
{

    int a=10;
    int &r=a;
    //int &r; // when we are declring reference we must intialize at the point only
    cout<<a<<endl;
    cout<<r<<endl;
    cout<<&a<<endl;
    cout<<&r<<endl;

    r =25;
    //r=b;
    cout<<a<<endl;
    cout<<r<<endl;
    cout<<&a<<endl;
    cout<<&r<<endl; 
}