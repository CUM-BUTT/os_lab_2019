#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
    pid_t child_pid;
    printf("parent id =%d\n",getpid());
    for(int i = 0;i<10;i++)
    {

        child_pid = fork ();
        if (!child_pid) 
        {   
            printf("child id =%d\n",getpid());
            exit (0);
        }

    }
    sleep(60);
    return 0;
}
//ps -ax
