#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int shmid,l;
char *ptr;
/***creating/accessing the shared memory segment********/
shmid=shmget((key_t)10,1000,IPC_CREAT|0666);
printf("the shmid of shared memory is %d\n",shmid);
printf("\n");
ptr=(char*)shmat(shmid,0,0);//attaching shared memory segments
printf("the address pointed by ptr is %u\n",ptr);
printf("\n enter data in shared memory=");
gets(ptr);
printf("the address pointed by ptr is %u\n",ptr);
}
