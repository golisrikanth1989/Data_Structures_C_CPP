/*If the value of the argument seconds is zero, then any previously made alarm request is cancelled.*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signum){
 
  printf("Inside handler function\n");
}
 
int main(){
 
 alarm(0);  // Cancelled the previous alarm
 
  for(int i=1;;i++)
 
    printf("%d : Inside main function\n",i);
    sleep(1);  // Delay for 1 second
  }
 
return 0;
}

/*the first alarm which was scheduled after 2 seconds is cancelled because of the second alarm for 0 second.*/
