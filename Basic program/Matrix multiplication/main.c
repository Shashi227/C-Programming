#include<stdio.h>
int main(){
    int a[2][2],b[2][2],c[2][2],sum=0,i,j,k;
    printf("enter the element in the ist array a[2][2]: \n");
    for (i=0;i<2;i++)
            for (j = 0;j<2;j++)
                    scanf("%d",&a[2][2]);
             printf("enter the element in the 2nd array b[2][2]: \n");
    for (i=0;i<2;i++)
            for (j=0;j<2;j++)
                    scanf("%d",&b[2][2]);
     for (i=0;i<2;i++)
            for (j=0;j<2;j++)
                for (k=0;k<2;k++)
                    sum=0;
            sum =sum+a[i][k]*b[k][j];
            c[i][j]=sum;
             for (i=0;i<2;i++)
            for (j=0;j<2;j++)
                printf("%d",c[i][j]);
             printf("\n");
            
}
    
   