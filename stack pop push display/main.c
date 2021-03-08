#include <stdio.h>
#include <stdlib.h>
#define n 10
void pop();
void push(int,int[],int);
void display();
int main(int argc, char** argv)
{
    int a[n],ch;
    int top,no;
    top=-1;
    printf("************************************************\n");
    printf("1. PUSH OPTION\n 2. POP OPTION\n 3. DISPLAY OPTION");
    printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter the number you wish to push in the array");
            scanf("%d",&no);
            top++;
            push(no,a[n],top);
            break;
        default:
            printf("Enter again");
            break;
       /* case 2:
            pop();
            break;
        case 3:
            display();
            break;
         */   
    }
    
    return (EXIT_SUCCESS);
}
void push( int x,int a[n],int top){
    if(top!=(n-1)){
        a[top]=x;
       }
    else
        printf("Stack is full");
  
printf("%d\n",a[top]);
    
}


