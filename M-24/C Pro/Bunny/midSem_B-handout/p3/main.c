/* 
 * MidSem-B, Problem 3
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
int hi;
scanf("%d",&hi);
int a[hi],mix=-1000000,sum=0;
for(int i=0 ;i<hi;i++){
scanf("%d",&a[i]);
if(mix<a[i]){
mix=a[i];}
sum+=a[i];
}
printf("Sum of array: %d\n ",sum);
printf("Maximum value: %d\n ",mix);
printf("Reversed array: ");
for(int i =hi-1;i>=0;i--){
printf("%d ",a[i]);


}
    
    return 0;
} 
