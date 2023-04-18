#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void main()
{
int pd[2], ret,Cnt = 0;
while(1)
{
ret = pipe(pd);
if(ret < 0)
{
printf("Max no of pipes Cnt = %d\n",Cnt);
break;
}
Cnt++;
printf("Pipe fds pd[0] = %d pd[1] = %d\n",pd[0],pd[1]); 
}
}