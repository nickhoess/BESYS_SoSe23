#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int *arraypointer = (int*) malloc(sizeof(int) *100);
    if(arraypointer == NULL)
    {
        fprintf(stderr,"malloc() failed\n");
        return -1;
    }
    arraypointer[100] = 0;

    return 0;
}