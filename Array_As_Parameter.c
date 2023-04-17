// C Program to demonstrate incorrect usage of sizeof() for
// arrays
#include <stdio.h>
 
void fun(int arr[])
{
    int i;
    int n = sizeof(arr) / sizeof(arr[0]);
    // sizeof should not be used here to get number
    //  of elements in array
    
    printf("%d\n",n);
 
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
    // executed two times only
}


/* int * fun1(int size)
{
    int *p;
    for(int i = 0;i<size;i++)
    {
        p[i]=i+1;
    }
    return p;
} */
 
// Driver Code
int main()
{
    int i;
    int arr[4] = { 0, 0, 0, 0 };
    
    fun(arr);
 
    // use of sizeof is fine here
    //for (i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
     //   printf(" %d ", arr[i]);
 
    //getchar();
    return 0;
}