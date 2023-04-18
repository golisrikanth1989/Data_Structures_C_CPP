#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#define DEFINED_KEY 25


// ==================reciever.c====================== /
struct {
long mtype;
char content[256];
}msg;

void main()
{ 
int msg_qid;
fprintf(stdout, "=====RECEIVER=====\n");
if((msg_qid = msgget(DEFINED_KEY,IPC_CREAT | 0666)) < 0) {
perror("msgget: "); exit(-1);
}
printf("Message Queue Id : %d" , msg_qid);
while(1) {
// memset(msg.content, 0x0, 256);
if(msgrcv(msg_qid, &msg, 256, 0, 0) < 0) {
perror("msgrcv: "); exit(-1);
}
puts(msg.content);
}
}
