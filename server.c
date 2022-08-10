
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

   int	get_strlen(int c)
{
	 static int i;
     static unsigned int len;
     int x = 0;
    if(!i || i == 0)
    {
    i = 0;
    len = 0;
    }
        if(i<32)
        {
            if(c == SIGUSR1)  
                len = len | 1;        
            i++;
        }
        if(i != 32)
           len = len<<1;
         if(i == 32)             
         { 
             i=0;
            return(len);
          }
        return(0);
}
    void handle_sigusr1(int c)
    {    
       
        static int i;
        static int len;
        static char *array;
        unsigned char put;
        if(len == 0)  
            len = get_strlen(c);
        if(len!= 0)
        {    
            printf("len es: %d\n", len);
            array =  (char*)malloc(sizeof(char)* len);
            len = 0; 
        }         
        /* if(!i)
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
        }  */
         
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
    pause();
    }

}