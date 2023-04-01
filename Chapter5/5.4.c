#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    const char *path = "/bin/ls";
    int rc = fork();

    if(rc < 0)
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if(rc == 0){
        printf("Im Child\n");
        //execlp(path,"ls", "-l",NULL);


        char *myargs[3];
        myargs[0] = ("ls");
        myargs[1] = ("-l");
        myargs[2] = NULL;
        execle(path, *myargs);
        // if (execRet < 0){
        //     printf("exec failed!\n");
        // }

        //execlp
        //execlp(path,"ls","-l",NULL);

        //execv
        /*char *myargs[2];
        myargs[0] = "ls";
        myargs[1] = NULL;
        execv(path,myargs);
        */
       
        //execvp
        /*char *myargs[3];
        myargs[0] = "ls";
        myargs[1] = "-l";
        myargs[2] = NULL;
        execvp("/bin/ls",myargs);
        */

    }else{
        wait(NULL);
        printf("Im Parent\n");
    }

}
