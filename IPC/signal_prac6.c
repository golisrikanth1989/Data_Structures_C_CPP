#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signum){
 
  printf("Inside handler function\n");
}
 
int main(){
 
  signal(SIGALRM,sig_handler); // Register signal handler
 
  alarm(2);  // Scheduled alarm after 2 seconds
 
  for(int i=1;;i++){
 
    printf("%d : Inside main function\n",i);
    sleep(1);  // Delay for 1 second
}
return 0;
}

/*So, for loop is executing, after 2 seconds sig_handler function is called and the execution of main function is paused. After execution of sig_handler function, in main function for loop execution is resumed. Here we use sleep function for delaying so that we can understand the flow of the execution. The for loop is an infinite loop, when we press an interrupt key (Ctrl+C), the execution will stop.*/


