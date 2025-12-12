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
int main(){
    int a;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        inde=-1;
        char str[10000];
        scanf("%s",str);
        int len = strlen(str);
        limit=len;
        int flag=0;
        int flag1=0;
        arr=(int*)malloc(len*sizeof(int));
        for(int j=0;j<len;j++){
                if(len%2==1){
                    if(!isfull() && j==len/2){
                        //printf("hi");
                        continue;
                    }
                }
                if((!isfull() && str[j]!=top())|| isempty()){
                    push(str[j]);
                }
                else if(str[j]==top() && !isempty()){
                    //printf("gvu");
                    pop();
                }
                //printf("%d\n",inde);
        }
        if(size()==0){
            flag=1;
        }
        inde=-1;
        int o=0;
        for(int j=0;j<len;j++){
                //printf("--2-- %d\n",inde);
                if( !isfull() && (str[j]=='[' || str[j]=='{' || str[j]=='(' )){
                    //printf("ki");
                    push(str[j]);
                    o=1;
                }
                else if(!isempty() && ((top()=='[' && str[j]==']') || (top()=='{' && str[j]=='}') || (top()=='(' && str[j]==')'))){
                    //printf("pop\n");
                    pop();
                }
                else if( !isfull() && (str[j]==']' || str[j]=='}' || str[j]==')' )) {
                    inde=0;
                    break;
                }
                else{
                    //printf("%d j - \n",j);
                    continue;
                }
        }
        if(inde==-1) flag1=1;
        if(flag && flag1 && o) printf("Balanced and Palindromic\n");
        else if(flag) printf("Palindromic\n");
        else if(flag1 && o) printf("Balanced\n");
        else printf("-1\n");
        //printf("%d %d",flag,flag1);
    }
}