#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();

    if(rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0)
    {
        printf("Children X: %d\n", x);
        x = 1;
        printf("Children X_new: %d\n", x);
    } else {
        wait(NULL);
        printf("Parent X: %d\n", x);
        x = 2;
        printf("Parent X_new: %d\n", x);
    }
    return 0;
}