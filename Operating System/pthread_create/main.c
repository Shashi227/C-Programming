/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 4 September, 2019, 12:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
# define THREAD 3
void HelloWorld()
{
    printf("Hello World\n");
    pthread_exit(NULL);
}
int main(int argc, char** argv)
{
    pthread_t thread[THREAD];
    int l,i;
    for(i=0;i<THREAD;i++)
    {
        l=pthread_create(&thread[i],NULL,HelloWorld,NULL);
    }
    return (EXIT_SUCCESS);
}

