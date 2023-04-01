#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char* charpointer = malloc(sizeof(char)*10);
    if(charpointer == NULL)
    {
        fprintf(stderr,"malloc() failed\n");
        return -1;
    }
    return 0;
}