#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 8
void PrintHello(void *threadid)
{
//sleep(1);
pthread_t thread_id = pthread_self();
/*The pthread_self() function is used to get the ID of the current thread. 
This function can uniquely identify the existing threads. But if there are multiple threads, 
and one thread is completed, then that id can be reused. So for all running threads, the ids are unique.*/
printf("Hello from thread %u\n",thread_id);
}
int main()
{
pthread_t
threads[NUM_THREADS];
int t;
for(t=0;t<NUM_THREADS;t++) {
printf("Creating thread %ld\n", t); 
pthread_create(&threads[t], NULL, PrintHello, (void *) &t);
perror("create");
}
}
