#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *stack;
char *stack1;
int max,inde;
int max1,index1;

int isfull1(){
    if(index1==max1) return 1;
    return 0;
}

int isempty1(){
    if(index1==-1) return 1;
    return 0;
}

int top1(){
    return stack1[index1];
}

int push1(int data){
    if(!isfull1()){
        stack1[++index1]=data;
        return 1;
    }
    return 0;
}

int pop1(){
    if(!isempty1()){
        return stack1[index1--];
    }
    return -1;
}

void display1(){
    for(int i=0;i<=index1;i++){
        printf("%d ",stack1[i]);
    }
    printf("\n");
}



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
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        inde=-1;
        index1=-1;
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==0 && y==0) {
            printf("yes\n");
            continue;
        }
        max=x;
        max1=y;
        stack=malloc(sizeof(char)*(x+1));
        stack1=malloc(sizeof(char)*(y+1));
        char str[x],str1[y];
        scanf("%s %s",str,str1);
        for(int j=0;j<x && str[j]!='\0';j++){
            if(str[j]=='x') pop();
            else push(str[j]);
            //display();
        }
        for(int j=0;str1[j]!='\0' && j<y;j++){
            if(str1[j]=='d') pop1();
            else push1(str1[j]);
            //display1();
        }
        //display();
        //display1();
        if(inde==-1 && index1==-1){
            printf("yes\n");
            continue;
        }
        if(inde!=index1){
            printf("no\n");
            continue;
        }
        int z=0;
        for(int j=0;j<=inde;j++){
            if(stack[j]!=stack1[j]){
                printf("no\n");
                z=1;
                break;
            }
        }
        if(z==1) continue;
        printf("yes\n");
        //printf("%s %s",stack,stack1);
    }
    return 0;
}
