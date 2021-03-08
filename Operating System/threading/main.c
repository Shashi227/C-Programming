#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

char character;
void *lettercount(int *a)
{ 
    int fd=*a,i;
    int size=10;
    char buffer[size];
    int count=0;
    int n=read(fd,&buffer,size);
    while(n)
    {
        for(i=0;i<size;i++)
            if(buffer[i]==character)
                count++;
         n=read(fd,&buffer,size);
    }
    close(fd);
    *a=count;
    pthread_exit(NULL);
}

int main(int argc, char** argv) 
{
    int ec,i,total=0;
    pthread_t threads[3];
    int input_fd=open("inputfile",O_RDONLY);
    int n=read(input_fd,&character,1);
    close(input_fd);    
    int fd[3];
    fd[0]=open("textfile1",O_RDONLY);
    fd[1]=open("textfile2",O_RDONLY);
    fd[2]=open("textfile3",O_RDONLY);
    for(i=0;i<3;i++)
    {   
        ec = pthread_create(&threads[i],NULL,lettercount,&fd[i]);
        if(ec)
            printf("thread create unsuccessful");
    }   
        for(i=0;i<3;i++)
    {   
        ec = pthread_join(threads[i],NULL);
        if(ec)
            printf("thread join unsuccessful");
        printf("Character %c has occurred %d times in file %d\n",character,fd[i],i+1);
        total=total+fd[i];
    }   
    printf("Total occurences: %d",total);
    return (EXIT_SUCCESS);
}