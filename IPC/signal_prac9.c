/*we will see how continuously we can set an alarm for every 2 seconds.*/
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signum){
 
  printf("Inside handler function\n");
 
  alarm(2);  // Schedule a new alarm after 2 seconds
}
 
int main(){
 
  signal(SIGALRM,sig_handler); // Register signal handler
 
  alarm(2);  // Schedule the first alarm after 2 seconds
 
  for(int i=1;;i++){
 
    printf("%d : Inside main function\n",i);
    pause(); // waiting until signal is handled
}
 
return 0;
}

/*We can see that the alarm is continuous in every 2 seconds. We reset the alarm in the sig_handler function.*/
