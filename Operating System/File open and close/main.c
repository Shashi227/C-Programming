#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main (int argc,char** argv){
    char my[30],fd1,fd2;
    fd1=open("file1.txt",O_RDONLY);
    read(fd1,&my,sizeof(my));
    fd2=open("file2.txt",O_WRONLY);
    write(fd2,&my,sizeof(my));
    close(fd1);
    close(fd2);
    return(0);
    
}