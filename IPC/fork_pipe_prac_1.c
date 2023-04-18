#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    int pd[2], ret, fret;
    char Buff[7];
    // memset(Buff,0x0,sizeof(Buff));
    ret = pipe(pd); // pipe(int pd[2])
    printf("ret = %d\n", ret);
    fret = fork();
    if (fret == 0)
    {
        printf("Working in Child Process=%d\n",fret);
        printf("Child Sending msg 2 the parent\n");
        close(pd[0]);
        sleep(5);
        write(pd[1], "NEX-G", 6);
        printf("IN child writing is done\n");
        printf("Working in Child Process=%d\n",fret);
        write(pd[1], "hello", 5);
    }
    else
    {
        close(pd[1]);
        //printf("%d\n",fret);
        printf("In Parent\n");
        printf("Rcved msg 4m the child\n");
        printf("Working in Parent Process=%d\n",fret);
        read(pd[0], Buff, 6);
        printf("Message = %s\n", Buff);
        printf("Working in Parent Process=%d\n",fret);
        read(pd[0], Buff, 6);
        printf("Message2 = %s\n", Buff);
    }
}