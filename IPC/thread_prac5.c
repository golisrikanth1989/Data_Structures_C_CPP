#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
char n[1024];
sem_t a;
void * read1()
{
while(1)
{
printf("Enter a string:");
scanf("%s",n);
sem_post(&a);
sleep(1);
}
}
void * write1()
{
while(1)
{
sem_wait(&a);
printf("The string entered is : %s\n",n);
}}
int main()
{
pthread_t tr, tw;
pthread_create(&tr,NULL,read1,NULL);
pthread_create(&tw,NULL,write1,NULL);
pthread_join(tr,NULL);
pthread_join(tw,NULL);
return 0;
}
