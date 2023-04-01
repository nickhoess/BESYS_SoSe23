#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if(argc < 2 || argc > 3)
    {
        fprintf(stderr,"Call ./memory-user [MB] [TIME (s)]\n");
        return -1;
    }
    int mb = atoi(argv[1]) * 1e6;
    if(mb == 0)
    {
        printf("MB > 0!\n");
        return -1;
    }

    struct timespec t_start;
    struct timespec t_end;

    char* array = (char*) malloc(sizeof(char) * mb);
    if(!array)
    {
        fprintf(stderr, "malloc() failed!\n");
        return -1;
    }

    clock_gettime(CLOCK_MONOTONIC,&t_start);

    if(argc == 3) {
        int time = atoi(argv[2]);
        if(time == 0)
        {
            fprintf(stderr,"TIME have to be > 0!\n");
            return -1;
        }
        while (1) {
            for (int i = 0; i < mb - 1; i++)
            {
                array[i] = 'a';
            }

            clock_gettime(CLOCK_MONOTONIC, &t_end);

            if ((t_end.tv_sec - t_start.tv_sec) >= time) {
                break;
            }
        }

    } else {

        int time = 30;

        while (1) {
            for (int i = 0; i < mb - 1; i++)
            {
                array[i] = 'a';
            }
       
            clock_gettime(CLOCK_MONOTONIC, &t_end);

            if ((t_end.tv_sec - t_start.tv_sec) >= time) {
                break;
            }
        }
    }

    free(array);
    printf("done\n");
    return 0;
}