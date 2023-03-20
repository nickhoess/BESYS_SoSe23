#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();

    if(rc < 0)
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if(rc == 0) {
        printf("Im child and my PID is: %d\n", getpid());
        //int retwait = wait(NULL);
        //printf("returnValue(Child) of wait is: %d\n", (int) retwait);
        
    } else {
        int waitReturnValue = waitpid(rc, NULL, 0);
        printf("ReturnValue of wait(NULL): %d\n",(int) waitReturnValue);
        printf("Im Parent\n");
    }
    return 0;
}