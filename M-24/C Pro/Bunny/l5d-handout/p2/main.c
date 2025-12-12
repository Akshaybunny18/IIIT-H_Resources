/*
 Lab 5D problem 2
*/
#include<stdio.h>
void che (char * per,int m){
    if(per[0]==')' || per[m-1]=='('){
            //return ;
        }
        int musi=0;
    for(int i=0;i<m;i++){
        if(per[i]=='('){
            musi++;
        }
        else if(per[i]==')'){
            musi--;
        }
        if(musi<0){
            return ;
        }
    }
    if(musi==0){
        printf("%s\n",per);
    }
}
void rec(char *per,int cl,int m){
    if(cl==m){
        che(per,m);
        return;
    }
    per[cl]='(';
    rec(per,cl+1,m);
    per[cl]=')';
    rec(per,cl+1,m);

}
int main(){
    int n;
    // write your code here
    scanf("%d",&n);
    char per[2*n+1]; 
    int m=2*n;  
    per[m] = '\0';
    rec(per,0,m); 
    return 0;
} 
