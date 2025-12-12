#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *arr;
int inde=-1,limit;

int isempty(){
    if(inde==-1){
        return 1;
    }
    else return 0;
}

int isfull(){
    if(inde==limit-1){
        return 1;
    }
    else return 0;
}

int pop(){
    if(!isempty()) return arr[inde--];
    else return 0; 
}
int top(){
    if(!isempty()){
        return arr[inde];
    }
    else return -1;
}
int push(int h){
    if (!isfull()) 
    {
        arr[++inde]=h;
    }
    else return 0;
}
int size(){
    return inde+1;
}
void display(){
    for(int i=0;i<=inde;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int a;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        inde = -1;
        int len;
        scanf("%d",&len);
        int str[len];
        limit=len;
        arr=(int*)malloc(len*sizeof(int));
        for(int i=0;i<len;i++){
            scanf("%d",&str[i]);
        }
        for(int i=0;i<len;i++){
            if(str[i]>top()){
                //printf("--%d %d--\n",inde,top());
                if(!isempty()){
                    pop();
                    while(str[i]>top()){
                        if(top()==-1) break;
                        //printf("hi");
                        pop(); 
                    }
                }
                push(str[i]);
                //printf("%d ii ;; ",str[i]);
            }
            else if(str[i]<=top()){
                push(str[i]);
            }
        }
        display();
    }
}