#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
int count = 0;
void* run_thread()
{
pthread_t thread_id = pthread_self();
printf("Thread %u: Current value of count = %d\n", thread_id, count);
printf("Thread %u incrementing count ...\n");
count++;
//sleep(1);
printf("Value of count after incremented by thread %u = %d\n", thread_id, count);
pthread_exit(NULL);
}
int main ()
{
pthread_t thread_array[4];
int i, ret, thread_num = 4;
for (i = 0; i < thread_num; i++)
{
if ((ret = pthread_create(&thread_array[i],NULL,run_thread,NULL)) == -1)
{
printf("Thread creation failed with return code: %d", ret);
exit(ret);
}
}
pthread_exit(NULL);
}
