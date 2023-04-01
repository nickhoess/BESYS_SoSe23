#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int* intpointer = NULL;
    printf("intpointer derefrenced is: %d\n", *intpointer);
}