#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5
void PrintHello(void *threadid)
{
long tid;
tid = (long)threadid;
printf("Hello World! It's me, thread #%ld!\n", tid);
}
int main()
{
pthread_t threads[NUM_THREADS];
int rc;
long t;
for(t=0;t<NUM_THREADS;t++)
{
printf("In main: creating thread %ld\n", t);
pthread_create(&threads[t], NULL, PrintHello, (void *)t);
}
/*Last thing that main() should do */ 
pthread_exit(NULL);
}
