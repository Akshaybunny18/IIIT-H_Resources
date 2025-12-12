/* 
 * Lab 4 Problem 2
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int hi;
	scanf("%d",&hi);
	int a[hi];
	for (int i=0;i<hi;i++){
	scanf("%d",&a[i]);}
	for(int i=0;i<hi;i++){
	if(a[i]==0){
	printf("%d ",a[i] );
	}}
	for(int i=0;i<hi;i++){
	if(a[i]==1){
	printf("%d ",a[i] );
	}}
	for(int i=0;i<hi;i++){
	if(a[i]==2){
	printf("%d ",a[i] );
	}}
	
	

    
    return 0;
} 
