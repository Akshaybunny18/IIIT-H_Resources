#include <stdio.h>
#include <stdlib.h>

int * stack;
int index=-1,max=1000000;

int push(int data){
    if(index==max-1){
        return 0;
    }
    stack[++index] = data;
    return 1;      
}

int pop(){
    if(index==-1){
        return -1;
    }
    return stack[index--];
}

int isempty(){
    if(index==-1){
        return 1;
    }
    return 0;
}

int isfull(){
    if(index==max-1){
        return 1;
    }
    return 0;
}


int main(){
    int n;
    scanf("%d",&n);
    stack = (int *)malloc(sizeof(int)*n);
    max = n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = 0;
    }
    int t=0;
    char cha[n];
    scanf("%s",cha);
    // int k=0;
    // int a[n];
    for(int i=0;i<n;i++){
        // char char1;
        char char1 = cha[i];
        // scanf(" %c",char1);
        if(char1==')'){
            if(index>=0 && stack[index-1]=='('){
                arr[pop()]=1;
                pop();
                arr[i]=1;
                t+=2;
                // arr[t++] = ')';
                // if(index==-1){
                //     for(int j=0;j<t;j++){
                //         a[k++] = arr[j];
                //     }
                //     t=0;
                // }
                // arr[t++] = '(';
            }
            else {
                arr[i]=0;
                continue;
            }
        }
        else if(char1=='('){
            // push(i);
            push('(');
            push(i);
            // arr[t++] = '(';
        }   
    }
    printf("%d\n",t);
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            printf("%c",cha[i]);
        }
    }
    printf("\n");
    return 0;
}