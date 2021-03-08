#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>           
#include <semaphore.h>
#define max 10
int q[10], front = 0, rear = 0;
sem_t mutex, full, empty;
void consume() {
    if(front==10)
        front=0;
    printf("Removed value %d\n",q[front++]);
}
void produce() {
    int x = rand() % 100;
    if(rear==10)
        rear=0;
    q[rear++]=x;
    printf("Produced value %d\n",x);
}
void *producer(void *arg) {
    for(int i=0;i<max;i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        produce();
        sem_post(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *arg) {
    for(int i=0;i<max;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        consume();
        sem_post(&mutex);
        sem_post(&empty);
    }
}
int main(int argc, char** argv) {
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 10);
    pthread_t th_1;
    pthread_t th_2;
    pthread_create(&th_1, NULL, producer, NULL);
    pthread_create(&th_2, NULL, consumer, NULL);
    pthread_join(th_1, NULL);
    pthread_join(th_2, NULL);
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    return (EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
double times[5];
char process[] = {'A', 'B', 'C', 'D', 'E'};
int turn = 0;

void StartNext(int tid)     //choose the next thread to run
{
    int i;
    for(i = (tid + 1) % 5; times[i] == 0; i = (i + 1) % 5)
        if(i == tid)    //if every thread has finished
            return;
    turn = i;
}

void *Run(void *tid)    //the thread function
{
    int i = (int)tid;
    while(times[i] != 0)
    {
        while(turn != i);   //busy waiting till it is its turn
        if(times[i] > 2)
        {
            printf("%c 2\n", process[i]);
            sleep(2);   //sleep is to simulate the actual running time
            times[i] -= 2;
        }
        else if(times[i] > 0 && times[i] <= 2)      //this thread will have finished after this turn
        {
            printf("%c %lf\n", process[i], times[i]);
            sleep(times[i]);
            times[i] = 0;
        }
        StartNext(i);   //choose the next thread to run
    }
    pthread_exit(0);
}

int main(int argc, char **argv)
{
    pthread_t threads[5];
    int i, status;

    if(argc == 6)
    {
        for(i = 0; i < 5; i++)
            times[i] = atof(argv[i + 1]);   //input the burst time of each thread
        for(i = 0; i < 5; i++)
        {
            status = pthread_create(&threads[i], NULL, Run, (void *)i);    //Create threads
            if(status != 0)
            {
                printf("While creating thread %d, pthread_create returned error code %d\n", i, status);
                exit(-1);
            }
            pthread_join(threads[i], 0);    //Join threads
        }
    }
    return 0;
}