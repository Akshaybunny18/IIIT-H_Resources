#include <stdio.h>
#include <stdlib.h>
int index=-1,limit=128;
int *stack;
int pop(){
    if(index==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[index--];
}

int push(int data){
    if(index==limit-1){
        printf("Stack is full\n");
        return -1;
    }
    stack[++index]=data;
    return 0;
}

int topelement(){
    if(index==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[index];
}

int isempty(){
    if(index==-1){
        return 1;
    }
    return 0;
}

int size(){
    return index+1;
}

int isfull(){
    if(index==limit-1){
        return 1;
    }
    return 0;
}


int main() {
    // Write C code here
    stack=(int*)malloc(limit*sizeof(int));
    free(stack);
    return 0;
}
       