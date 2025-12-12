/*
 Assignment 6 problem 3
*/
#include<stdio.h>
#include<string.h>

int main()
{
    // write your code here
    FILE *hi;
    FILE *hi2;
    FILE *hi3;
    hi3=fopen("output.txt","w");
    hi=fopen("input1.txt","r");
    hi2=fopen("input2.txt","r");
    FILE *hi4;
    hi4=fopen("input2.txt","r");
    char str[100000];
    char str1[100000];
    while(fscanf(hi,"%s",str)==1){
        int i=0;
        while(str[i]!='\0'){
            i++;
        }
        i--;
        while(i>=0){
            fputc(str[i],hi3);
            i--;
        }
        fputc('\n',hi3);
    }
    fclose(hi);
    fscanf(hi4,"%s",str1);
    while(fscanf(hi2,"%s",str)==1){
        int i=strlen(str);
        i--;
        while(i>=0){
            fputc(str[i],hi3);
            i--;
        }
        if(fscanf(hi4,"%s",str1)!=1) continue;
        fputc('\n',hi3);
    }
    fclose(hi2);
    fclose(hi3);
    
    return 0;
}
