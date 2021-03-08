#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n,r,a;
    n=3;
    printf("enter the number of packets:%d\n",n);
    for (i=1;i<n;i++)
        printf("the packets sent is: %d\n",i);
    r=rand()%2;
    if(r==1)
    {
        a=rand()%2;
        if(a==1){
        printf("Acknowledge number: %d\n",i+1);
    }
    else
    {
        printf("no Acknowledge number : %d\n",i+1);
        i--;
    }
    }
    else
    {
        printf(" Time out,resend\n");
        i--;
    }
    return(0);
    }
    