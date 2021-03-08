#include <stdio.h>
#include <stdlib.h>
#include  <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv)
{   int a,b,c,d,x = 10,y = 2;
printf("\n *******using the fork processing call : *********\n");
    c = fork();
    if(c==0)
    {
         a = getpid();
         b = getppid();
        int sum = x+y;
        printf("\n Addition of these numbers is = %d \n",sum);
        printf("Process id : %d  and Parent process id : %d \n",a,b);
    }
    else{
        a = getpid();
        b = getppid();
            int sub = x-y;
        printf("\n subtraction of these numbers is = %d \n",sub);
        printf("Process id : %d  and Parent process id: %d \n",a,b);
         d = fork();
            if(d==0){
                   a = getpid();
                   b = getppid();
               int div = x/y;
              
               printf("\nthe division of the numbers = %d \n",div);
               printf("Process id : %d  and Parent process id : %d \n",a,b);
             }
            else{
                   a = getpid();
                   b = getppid();
                   int mul = x*y;
               printf("parent process \n");
               printf("Multiplication of these numbers =   %d \n",mul);
               printf("Process id : %d  and Parent process id : %d \n",a,b);
                               }
     }
    return (EXIT_SUCCESS);
}

