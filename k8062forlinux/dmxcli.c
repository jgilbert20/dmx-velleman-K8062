/*Simple test program for Velleman k8062 driver*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include "dmx.h"
#include <stdio.h>
#include <stdlib.h>

int *dmx_maxchannels;
int *dmx_shutdown;
int *dmx_caps;
int *dmx_channels;

int *shm;
int shmid;

extern int errno;

typedef char BYTE;

void dmx_open()
{
    
    shmid=shmget(0x56444D58,sizeof(int)*522, 0666);
    shm=(int *)shmat(shmid,NULL,0);
    dmx_maxchannels=shm;
    dmx_shutdown=shm+1;
    dmx_caps=shm+2;
    dmx_channels=shm+10;
}

void dmx_close()
{
    shmdt(shm);
}

int main(int argc,char *argv[])
{
dmx_open();
int ch,n;

if(shmid==-1){
	puts("Error: Unable to connect to DMX daemon.\n");
	printf("System returned error %d\n",errno);
	exit(-2);
}

 if( argc != 3 )
   {
     puts( "Must pass two numbers - channel and level" );
     exit(-3);
   }
 
 char *a = argv[1];
 ch = atoi(a);
 
 char *b = argv[2];
 n = atoi(b);
 
    if(ch==0)
      exit(-1);

    
   if(ch>0 && ch < 513){
     --ch;
     if(n>-1 && n<255){
       dmx_channels[ch]=(BYTE)n;
     }
   }
 
 dmx_close();
}
