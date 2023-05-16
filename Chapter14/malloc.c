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
    void* nullpointer = NULL;
    void* othernullpointer = NULL;
    void* anotherothernullpointer = nullpointer;
    fprintf(stderr,"nullpointer adress: %p\nanother nullpointer: %p\nganzandererpointer: %p\n", nullpointer, othernullpointer, anotherothernullpointer);

    return 0;

}