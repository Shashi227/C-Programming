#include <stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
clock_t calculate(void);
double time_spent=0.0;
clock_t begin,end,begin1,end1,begin2,end2,begin3,end3,begin4,end4;
int count=0,count1=0,count2=0;
int main(){
    printf("\tOS-SEQUENTIAL\n");
    printf("Character taken is a\n");
    begin4=clock();
    double g;
    clock_t h;
    g=calculate();      
    end4=clock();
    h=(end4-begin4)+g;
  time_spent+=(double)(h)/(double)(CLOCKS_PER_SEC*1000000);
  printf("The total frequency is %d",(count+count1+count2));
  printf("\nTime elapsed is %1.10lf seconds\n",time_spent);
//  while(time_spent!=0.0000000150){
//      count=0,count1=0,count2=0;
//      main();
//  }
}
clock_t calculate(){
    // We take input from user for the character.
    begin = clock();
    int fd1,fd2,fd3,fd4,a,b;
        char buf1[17],buf2[24];
    char c='a';
    char d;
    int f;
    creat("input.txt",0777);
    fd1=open("input.txt",O_RDWR);
   // printf("%d",fd1);
    if(fd1!=0){
    //char s[20];
    a=write(fd1,&c,2);
    lseek(fd1,0,0);
    f=read(fd1,&d,2);
    end = clock();
    printf("\nCharacter \'%c\' Written to the input file input.txt\n",d);
    printf("--------------%c,%d\n",d,f);
    }
    else{
        printf("wrong file");
    }
    // creating three files with some random data....
    begin1=clock();
    creat("file_a.txt",0777);
    creat("file_b.txt",0777);
    creat("file_c.txt",0777);
    fd2=open("file_a.txt",O_RDWR | O_RDONLY);
    write(fd2,"this is a testaaa",17);
    lseek(fd2,0,0);
    int g;
    g=read(fd2,buf1,17);
    for(int i=0;buf1[i]!='\0';i++){
        if(buf1[i]==d){
            count++;
        }
    }
    end1=clock();
  printf("The frequency of the entered character in file_a is %d\n",count);
  begin2=clock();
  close(fd2);
  // opening 2nd file and searching for character stored in variable c.
  fd3=open("file_b.txt",O_RDWR);
  write(fd3,"this is another shashi kumar hjdffdj",24);
  lseek(fd3,0,0);
  int h,k;
  k=read(fd3,buf2,24);
for(int h=0;buf2[h]!='\0';h++){    
  if(buf2[h]==d){
          count1++;
      }
  }
  end2=clock();
  printf("The frequency of the entered character in file_b is %d\n",count1);
  begin3=clock();
  close(fd3);
  // opening the last file and search for character stored in variable c.
  fd4=open("file_c.txt",O_RDWR);
  int t,s;
  char buf3;
  write(fd4,"Hello ba thismsruasusercs is another testaaa for ya ba lets see what we gat msruasjhdfdj",65);
  lseek(fd4,0,0);
  while((read(fd4,&buf3,1))!=0){
  if(buf3==d){
          count2++;
      }
  }
  close(fd4);
  end3=clock();
  printf("The frequency of the entered character in file_c is %d\n--------------------------------------------------------------------------------------",count2);
  printf("\nThe frequencies are \n From file_a - %d\n--------\n From file_b - %d\n----------\n From file_c - %d\n-----------------\n-----------------\n",count,count1,count2);
  return ((end-begin)+(end1-begin1)+(end2-begin2)+(end3-begin3));
}