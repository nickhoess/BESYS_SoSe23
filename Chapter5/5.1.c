#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("Parent X: %d\n", x);
    int rc = fork();

    if(rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if(rc == 0)
    {
        printf("Children X: %d\n", x);
        x = 1;
        printf("Children (x changed): %d\n", x);
    } else
    {
        wait(NULL);
        printf("Parent(x changed): %d\n", x);
    }
    return 0;
}