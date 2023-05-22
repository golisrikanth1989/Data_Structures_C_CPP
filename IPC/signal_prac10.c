/*we will see how we can delay the alarm already scheduled. We will use SIGINT signal for interrupt. When user type Ctrl+C in keyboard, SIGINT signal will generate.*/


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signum){
 
  if(signum == SIGALRM){         //signal handler for SIGALRM
 
    printf("Inside handler function for SIGALRM\n");
    alarm(2);
  }
  if(signum == SIGINT){         // signal handler for SIGINT
    printf("\nSnoozing for 5 seconds....\n");
    alarm(5);
  }
 
}
 
int main(){
 
  signal(SIGALRM,sig_handler); // Register signal handler for SIGALRM
  signal(SIGINT,sig_handler); // Register signal handler for SIGINT
 
  alarm(2);  // Schedule the first alarm after 2 seconds
 
  for(int i=1;;i++){
 
    printf("%d : Inside main function\n",i);
    pause(); // waiting until signal is handled
  }
 
return 0;
}

/* we can see that when user type Ctrl+C the alarm is reset 5 seconds. In this program we have used only one handler function for two different signals but in the handler function it has been checked that for which signal the handler function is being called.*/
