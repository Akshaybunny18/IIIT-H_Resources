#include <stdio.h>
#include <stdbool.h>
int main(){
    bool a = true;
    char b = 'a';
    int c = 5;
    int q =55;
    char u = 'k';
    bool t = false ;
    printf("%p %p %p %p %p %p",&a,&b,&c,&q,&u,&t);
    while(c--);
    printf("%d",c);
}