#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void fun(int sig)
{
printf("I got signal %d\n", sig);
}int main()
{
(void) signal(SIGINT, fun); 
while(1)
{
printf("Hello World!\n");
sleep(1);
}
}
