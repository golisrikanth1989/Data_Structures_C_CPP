#include<iostream>
#include<stdio.h>


using namespace std;

int main()
{

    //Normal Array Declaration
    int A[5];
    A[0] =10;
    A[1] =11;
    A[2] =12;
    A[3] =13;
    A[4] =14;

    cout<<sizeof(A)<<endl;
    cout<<A[1]<<endl;
    printf("%d\n",A[2]);
    printf("%d\n",A[6]); // Accessing array out of bounds but still prits garabge value
    cout<< " "<<endl;
  
    // Array Initlization
    int B[]={20,21,22,23,24,25,26,27};

    cout<<sizeof(B)<<endl;
    cout<<B[1]<<endl;
    printf("%d\n",B[7]);
    // Accessing array out of bounds but still prints garabge value without any error
    printf("%d\n",B[10]); 
    cout<< " "<<endl;


    // Array Accessing
    int C[10]={20,21,22,23,24,25,26,27};

    cout<<sizeof(C)<<endl;
    cout<<C[1]<<endl;
    printf("%d\n",C[7]);
    printf("%d\n",C[8]);
    printf("%d\n",C[9]);
    cout<< " "<<endl;

    for (int x:C)
    {
        cout<<x<<endl;
    }

    // Input from the user for the size of array
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n]; // we can create or declare but not intialize
    cout<<"Enter the elements of the array"<<endl;

    arr[0]=2;

    for (int x:arr)
    {
        cout<<x<<endl; // Prints the garbage values except the arr[0]
    }


 return 0;


}