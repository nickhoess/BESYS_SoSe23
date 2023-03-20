#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int file = open("text.txt", O_RDWR | O_CREAT);
    if(file < 0)
    {
        fprintf(stderr,"file open failed");
        exit(1);
    }
    int rc = fork();

    if(rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        write(file,"Im Child\n", 8);
    } else {
        write(file,"Im Parent\n", 9);
    }
    return 0;



}