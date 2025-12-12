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
        return 1;
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
int canReach(int start, int target, int X, int Y) {
    //int visited[1000000] = {0};
    push(start);
    //visited[start] = 1;

    while (!isempty()) {
        int current = pop();

        if (current == target) return 1;

        int addd = current + X;
        if (addd <= target ){//&& !visited[addd]) {
            //visited[addd] = 1;akshay18
            push(addd);
        }

        int mulll = current * Y;
        if (mulll <= target ){//&& !visited[mulll]) {
            //visited[mulll] = 1;
            push(mulll);
        }
    }

    return 0;
}
int main(){
    int N, M, X, Y;
    scanf("%d %d %d %d", &N, &M, &X, &Y);
    arr=(int*)malloc(10000*sizeof(int));
    limit=10000;
    int str[N];
    for(int i=0;i<N;i++){
        scanf("%d",&str[i]);
    }
    for (int i = 0; i < N; i++) {
        if (canReach(str[i], M, X, Y)) {
            printf("Yes\n");
            free(arr);
            return 0;
        }
    }
    printf("No\n");
    free(arr);
    return 0;
}