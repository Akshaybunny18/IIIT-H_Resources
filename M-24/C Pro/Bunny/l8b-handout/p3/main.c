/*
 Lab 5D problem 3
*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void toLowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}
int main()
{
    FILE *a,*b;
    char y[10000];
    char u[10000];
    int x=2;
    a = fopen("words.txt","r");
    while(fscanf(a,"%s",y)==1){
        b = fopen("words.txt","r");
        toLowercase(y);
        //printf("%s\n",y);
        x=2;
        while(fscanf(b,"%s",u)==1){
            toLowercase(u);
            //printf("%s ",u);
            if(!(strcmp(y,u))){
                x--;
                //break;
            }
            if(x==0){
                break;
            }
        }
        //printf("hii\n");
        fclose(b);
        if(x==1){
            printf("%s",y);
            fclose(a);
            return 0;
        }
    }
    fclose(a);
    return 0;
}
