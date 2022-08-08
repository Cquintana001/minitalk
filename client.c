
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void send_bits(int pid, char c)
{
    int i = 0;
    int out = c;
    while(i<8)
    {
         
        if(out & 1==1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        out = out<<1;
        i++;
    }
}
int main(int argc, char *argv[])
{
    int pid;
    char *str_to_send;
    int x;

    x = 0;
    pid = atoi(argv[1]);
    
    str_to_send = argv[2];
    while(str_to_send[x])
    {
       
        send_bits(pid, str_to_send[x]);
        x++;
    }
    return(0);
}