/*
 Assignment 6 problem 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fun(char *str1,char *str2){
    if(strcmp(str1,str2)<0) return str1;
    else return str2;
}

int fun2(char *str1,char *str2){
    if(strcmp(str1,str2)<0) return 1;
    else if(strcmp(str1,str2)>0) return 0;
    else return 2;
}

int main(){
    FILE *hi;
    FILE *hi2;
    hi2=fopen("names.txt","r");
    hi=fopen("names.txt","r");
    char str1[17];
    char str2[17];
    char str3[17];
    
    while(fscanf(hi2,"%s",str2)!=EOF){
        if(str2[0]=='&') break;
    }
   
    fscanf(hi,"%s",str1);
    fscanf(hi2,"%s",str2);
    int c=0;
    int freq=0;
    while(c!=11){
        int result=fun2(str1,str2);
        if(result==1) { 
            if(strcmp(str3,str1)!=0) {  
                if(c>0) printf("%d ",freq); 
                strcpy(str3,str1);
                freq=1; 
                c++;
            } else {
                freq++; 
            }
            if(fscanf(hi,"%s",str1)!=1) break;  
        } 
        else if(result==0) {  
            if(strcmp(str3,str2)!=0) {  
                if(c>0) printf("%d ",freq);  
                strcpy(str3,str2);
                freq=1; 
                c++;
            } else {
                freq++;  
            }
            if(fscanf(hi2,"%s",str2)!=1) break;  
        } 
        else { 
            if(strcmp(str3,str1)!=0) { 
                if(c>0) printf("%d ",freq);  
                strcpy(str3,str1);
                freq=2; 
                c++;
            } else {
                freq+=2;  
            }
            if(fscanf(hi,"%s",str1)!=1 || fscanf(hi2,"%s",str2)!=1) break;
        }
    }
}
