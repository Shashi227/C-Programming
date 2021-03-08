#include<stdio.h>
#include<stdlib.h>
void fibo (int a){
    int f1=0,f2=1,i ,next;
    if (a<1)
    return;
    for (i=1;i<a;i++){
    printf(" %d ",f2);
    next=f1+f2;
    f1=f2;
    f2=next;

    }
}
int main(){
    int x;
    printf("enter the fibo number \n");
    printf("enter only integer number \n");
    scanf("%d",&x);
    fibo(x);
    return 0;
}