#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
int ret;
ret = fork();
printf("%d\n",ret);
if(ret==0)
{
printf("I am the child,my process ID is %d\n",getpid());
printf("The child's parent process ID is %d\n",getppid());
}
else
{
printf("I am the parent,my process ID is %d\n",getpid());
printf("The parent's parent process ID is %d\n",getppid());
}
}