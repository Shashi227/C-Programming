#include<stdio.h>
#include<stdlib.h>
int main(){
    int x[10],y[10],i,j,range,dist[10][10];
    for (i=0;i<10;i++){
        x[i]=1+rand()%10;
        y[i]=1+rand()%50;
    }
    printf("\ndistance matrix is:\n");
    for (i=0;i<10;i++)
    {
         for(j=0;j<10;j++)
        {
            dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+((y[i]-y[j])*(y[i]-y[j])));
            printf("%d\t",dist[i][j]);
        }
         printf("\n");
     }
    printf("Enter the range of neighbours:\n");
    scanf("%d",&range);
    for (i=1;i<10;i++)
    {
        printf("\n the node %d is nighbours to node :\t  ",i);
        for (j=1;j<11;j++){
    if (dist[i][j]<=range)
        printf("%d\t",j);
        }
    }
    return(0);
}