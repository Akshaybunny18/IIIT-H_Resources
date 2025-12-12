#include <stdio.h>
#include <stdlib.h>

long long int *stack;
long long int max=100000,index=-1;

int isempty(){
    return index==-1;
}

int isfull(){
    return index==max-1;
}

int push(long long int data){
    if(isfull())
        return 0;
    stack[++index]=data;
    return 1;       
}

long long int pop(){
    if(isempty())
        return -1;
    return stack[index--];
}


int main(){
    int n;
    scanf("%d",&n);
    max=n;  
    stack=(long long int*)malloc(n*sizeof(long long int));
    char arr[n];
    scanf("%s",arr);
    for(int i=0;i<n;i++){
        char c=arr[i];
        // scanf(" %c",&c);
        if(c>='0' && c<='9'){
            push(c-'0');
        }
        else{
            long long int a=pop();
            long long int b=pop();
            if(c=='+')
                push(a+b);
            else if(c=='-')
                push(b-a);
            else if(c=='*')
                push(a*b);
        }           
    }
    printf("%lld",pop());
    return 0;
}