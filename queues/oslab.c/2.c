#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
int main( int arg c, char *argv[])
{
    pid_t pid=fork();
    if(fork==-1){
        printf("Error");
    }else if(fork==0)
    {
        printf("CHild process id=%d",getpid());
        execl("%LCM",LCM,argv[1],argv[2],NULL);
    }
    else{
        printf("Inside parent process %d",getpid());
    }
}