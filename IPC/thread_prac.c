#include<stdio.h>
#include <pthread.h>
void * thread1()
{
while(1)
printf("Hello!!\n");
}
void * thread2()
{
while(1)
printf("How are you?\n");
}
void main()
{
  // thread1();
  // thread2(); 
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,thread1,NULL);
pthread_create(&tid2,NULL,thread2,NULL);
//pthread_join(tid1,NULL);
//pthread_join(tid2,NULL);
pthread_exit(NULL);
}
