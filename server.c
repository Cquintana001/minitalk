
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

    unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}
    void handle_sigusr1(int c)
    {    
      
        static int i;
        unsigned char put;
        int x = 0;
        if(!i)
        {   
            i = 0;  
            put  = 0;           
        }
        if(i < 8)
        {
            if(c == SIGUSR1)  
                put = put | 1;        
            i++;
        }
        if(i != 8)
           put = put<<1;
         if(i == 8)
        {             
            write(1, &put, 1);
            i = 0;
        } 
         
    }

int main()
{
    static int out;

    out = 0;
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