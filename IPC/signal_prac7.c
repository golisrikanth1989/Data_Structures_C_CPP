#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signum){
 
  printf("Inside handler function\n");
}
 
int main(){
 
  signal(SIGALRM,sig_handler); // Register signal handler
 
  alarm(4);  // Scheduled alarm after 4 seconds
  alarm(1);  // Scheduled alarm after 1 seconds
 
  for(int i=1;;i++){
 
    printf("%d : Inside main function\n",i);
    sleep(1);  // Delay for 1 second
}
 
return 0;
}

/*
Generating SIGALRM using signal() function cannot be stacked. 

Only one SIGALRM generation can be scheduled. Successive calls of signal() function reset the alarm clock of the calling process.

The first alarm which was scheduled after 4 second is not calling the handler function. The second alarm which was scheduled after 1 second is reset the alarm.



*/
