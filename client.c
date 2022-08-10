
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void send_strlen(int pid, int len)
{

    int i = 0;
     int result;
    while(i<32)
    {
         result = len & 2147483648;
        
        if(result)
            kill(pid, SIGUSR1);
        else 
            kill(pid, SIGUSR2);
        usleep(300);
        len = len<<1;
        i++;
    }
}
void send_bits(int pid, char c)
{
    int i = 0;
    int out = c;
    int result;
    while(i<8)
    {
         result = out & 128;
        
        if(result)
            kill(pid, SIGUSR1);
        else 
            kill(pid, SIGUSR2);
        usleep(300);
        out = out<<1;
        i++;
    }
}
int main(int argc, char *argv[])
{
    int pid;
    char *str_to_send;
    int x;
    int len;
    x = 0;
    pid = atoi(argv[1]);
    
    str_to_send = argv[2];
    while(str_to_send[x]) // sustituir por ft_strlen del Libft
        x++;
    len = x;
    send_strlen(pid, len);
    x = 0;
    while(str_to_send[x])
    {
        
        send_bits(pid, str_to_send[x]);
        x++;
    }
    return(0);
}