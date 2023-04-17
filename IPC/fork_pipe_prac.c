#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>


#define msgsize 16

int main()

{
    char *msg1="hello world 1";
    char *msg2="hello world 2";
    char *msg3="hello world 3";

	char inbuf[msgsize];

	int p[2],i;

    int pid;

	if(pipe(p) < 0)
    {
        exit(1);
    }
	
    if((pid=fork())>0)
    {
		close(p[0]);
        printf("write process is running 1\n");
		write(p[1],msg1,msgsize);
		printf("write process is running 2\n");
		write(p[1],msg2,msgsize);
		printf("write process is running 3\n");
		write(p[1],msg3,msgsize);
        close(p[1]);
    }
    else{
        close(p[1]);
	    for(i=0;i<3;i++)
	    {
		    read(p[0],inbuf,msgsize);
		    printf("%s\n",inbuf);
	    }
    }
return 0;

}
