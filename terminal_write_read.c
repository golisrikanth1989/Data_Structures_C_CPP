#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main( )
{
int ret;
char buf[512];
ret=read(0,buf,3);
printf("return value from read : %d\n",ret);
write(1,buf,512);
return 0;
}