#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
printf("This is to demonstrate the fork()\n");
fork();
printf("Hello World\n");
}