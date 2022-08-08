
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

    void handle_sigusr1()
    {
       if(SIGUSR1)
            printf("1\n");
       else if(SIGUSR2)
            printf("0\n");
    }

int main()
{
    pid_t pid = getpid();
    printf("el pid es : %d\n",pid);
    while(1)
    {
    struct sigaction sa;
   
    sa.sa_handler = &handle_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    }

}