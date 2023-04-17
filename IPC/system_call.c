#include<unistd.h>
#include<stdio.h>
int main()
{
    int n;
    n = write(1,"Hello\n",6);
    printf("Value of n is %d\n",n);

    char b[30];
    read(0,b,10);
    write(1,b,10);
}