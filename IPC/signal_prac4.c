#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
int main(void)
{
void sigint_handler(int sig); /*prototype */
char s[200];/* set up the handler */
if (signal(SIGINT, sigint_handler) == SIG_ERR) {
perror("signal");
exit(1);
}
printf("Enter a string:\n");
if (gets(s) == NULL) perror("gets");
else
printf("You entered %s",s);
}
void sigint_handler(int sig)
{
printf("Not this time!\n");
}
