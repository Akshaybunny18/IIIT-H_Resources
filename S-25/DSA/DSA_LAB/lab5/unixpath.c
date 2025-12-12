#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int max,inde;

int isfull(){
    if(inde==max) return 1;
    return 0;
}

int isempty(){
    if(inde==-1) return 1;
    return 0;
}

int top(){
    return stack[inde];
}

int push(int data){
    if(!isfull()){
        stack[++inde]=data;
        return 1;
    }
    return 0;
}

int pop(){
    if(!isempty()){
        return stack[inde--];
    }
    return -1;
}

void display(){
    for(int i=0;i<=inde;i++){
        printf("%c",stack[i]);
    }
    printf("\n");
}



int main(){
    inde=-1;
    max=1000000;
    stack=malloc(sizeof(char)*1000000);
    char str[1000000];
    //int h;
    scanf("%s",str);
    //printf("hi");
    int n;
    n=strlen(str);
    int i=0;
    push('/');
    while(i!=n){
        if(str[i]=='.' && str[i+1]=='.'){
            if(top()=='/') pop();
            while(top()!='/'){
                int c=pop();
                if(c==-1) break;
            }
            i++;
            continue;
        }
        if(str[i]=='/' && top()=='/') {
            i++;
            continue;
        }
        if(str[i]=='/' && top()!='/'){
            push('/');
            i++;
            continue;
        }
        if(str[i]=='.' && str[i+1]!='.'){
            i++;
            continue;
        }
        if(str[i]!='.' && str[i]!='/'){
            push(str[i]);
            i++;
        }
    }
    if(top()=='/') pop();
    if(isempty()) push('/');
    display();


    return 0;
}
