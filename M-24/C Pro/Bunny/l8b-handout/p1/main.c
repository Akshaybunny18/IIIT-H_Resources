/*
 Lab 8A problem 1
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    // Pls use long long int for storing and printing answer.
    FILE *ptr;
    ptr = fopen("number.txt","r");
    long long int x=0;
    char y= fgetc(ptr);
    while(y!=EOF){
        if(y==',' || y==' ' || y=='\n'){
            y=fgetc(ptr);
            continue;
        }
        x= (x*10) + (y-48);
        y=fgetc(ptr);
    }
    printf("%lld",x*x);
    fclose(ptr);
    return 0;
}