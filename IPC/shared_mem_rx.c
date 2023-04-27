#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int shmid;
char *ptr;
/******************creating /accesing shared memory segments***********/
shmid=shmget((key_t)10,1000,IPC_CREAT|0666);
printf("the shmid of shared memory is %d\n",shmid);
/*****************attaching shared memory segments to PAS**********/
ptr=(char*)shmat(shmid,0,0);
printf("the address pointed by ptr is %u\n",ptr);
printf("the message in shared memory is:%s\n",*ptr);
printf("the message in shared memory is:%s\n",(ptr+5));
shmdt(ptr);
printf("the message in shared memory is:%s\n",ptr);
//
shmctl(shmid,IPC_RMID,0);//deleteing shared memory segment
}
