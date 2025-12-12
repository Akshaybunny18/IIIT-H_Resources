#include <stdio.h>
int main()
 {
int a=25,b=15;
a=a+b-(b=a);
printf("%d %d",a,b);
return 100000; 
}
