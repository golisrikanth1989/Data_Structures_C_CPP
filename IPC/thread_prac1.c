#include<stdio.h>
#include <pthread.h>
void  thread1(void *arg)
{
while(1){
printf("\nHello!!:%s", arg);
sleep(1);
}
}
void  thread2(char *arg)
{
while(1){
printf("\nYou are running: %s",arg);
sleep(1);
}
}
int main()
{
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,thread1,"NEXG");
pthread_create(&tid2,NULL,thread2,"thread");
pthread_join(tid1,NULL); pthread_join(tid2,NULL);
return 0;
}
