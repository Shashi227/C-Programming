#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char str1[12]="hello";
    char str2[12]="world";
    char str3[12];
    
    strcpy(str3,str1);
    strcat(str1,str2);
    int length_str1=strlen(str1);
    int value = strcmp(str1,str2);
    printf("str3=%s\n",str3);
    printf("strcat=%s\n",str1);
    printf("string_length=%d \n",length_str1);
    printf("strcmp=%d \n",value);
    
    return 0;
}