#include <stdio.h>
#include <stdlib.h>
int front=-1,rear=-1;
int* q;
int x;

// -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all
// -fsanitize=address,undefined -g
// -fsanitize=address,undefined -g -fno-sanitize-recover=all

int isempty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(){
    if((rear+1)%x==front){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int data){
    if(isfull()){
        printf("Queue is full\n");
    }
    else if(isempty()){
        front=rear=0;
        q[rear]=data;
    }
    else{
        rear=(rear+1)%x;
        q[rear]=data;
    }
}

int dequeue(){
    if(isempty()){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        int temp=q[front];
        front=rear=-1;
        return temp;
    }
    else{
        int temp=q[front];
        front=(front+1)%x;
        return temp;
    }
}

void display(){
    if(isempty()){
        printf("Queue is empty\n");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d ",q[i]);
            i=(i+1)%x;
        }
        printf("%d\n",q[rear]);
    }
}

int first(){
    if(isempty()){
        printf("Queue is empty\n");
    }
    else{
        return q[front];
    }
}

int recent(){
    if(isempty()){
        printf("Queue is empty\n");
    }
    else{
        return q[rear];
    }
}

int main(){
    printf("Enter size of Data Strcuture : ");
    scanf("%d",&x);
    q=(int*)malloc(x*sizeof(int));
}