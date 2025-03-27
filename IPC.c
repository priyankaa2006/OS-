
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#define SEGSIZE 100
int main(int argc,char*argv[])
{
int shmid,cntr;
key_t key;
char*segptr;
char buff[]="poooda....";
key=ftok(".",'s');
if((shmid=shmget(key,SEGSIZE,IPC_CREAT|IPC_EXCL|0666))==-1)
{
if((shmid=shmget(key,SEGSIZE,0))==-1)
{
perror("shmget");
exit(1);
}
}
else
{
printf("creating a new shared memory seg \n");
printf("SHMID:%d",shmid);
}
system("icps -m");
if((segptr=(char*)shmat(shmid,0,0))==(char*)-1)
{
perror("shmat");
exit(1);
}
printf("writing data to shared memory...\n");
strcpy(segptr,buff);
printf("DONE \n ");
printf("reading data from shared memory....\n");
printf("DATA:-%s \n",segptr);
printf("DONE \n");
printf("removing shared memory segment...\n");
if(shmctl(shmid,IPC_RMID,0)==-1)
printf("can't remove shared memory segment....\n");
else
printf("removed successfully");
}


/*creating a new shared memory seg 
SHMID:12345
sh: 1: icps: not found
writing data to shared memory...
DONE  
reading data from shared memory....
DATA:-poooda....  
DONE  
removing shared memory segment...
removed successfully
*/
