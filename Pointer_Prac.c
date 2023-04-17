#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a = 10;
    int *p;
    p=&a;
    printf("%d\n",a);
    printf("%d\n",*p);

    int A[5] = {2,4,6,8,9};
    int *pa;
    pa = A; //Don't Assign &A for arrays (you can assign &A[0]) 

    for(int i=0;i<5;i++)
    {
     printf("%d\n",pa[i]); 
    }

    int *paa;
    //paa = new int[5];

    //delete [ ] paa;
    free(paa);

    return 0;
}