#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cuu=0,n;
int w,wx,wy,mx,my;
int chee(int **a,int r,int c) {
	//akshay
	if(a[r][c]==1||a[r][c]==3) {
		for(int i=r-1;i>=0;i--) {
			if(a[i][c]!=0&&a[i][c]!=5){
				return 0;
			}
			if(a[i][c]==5){
				break;
			}
		}
	}
	if(a[r][c]==2) {
		for(int i=r-1;i>=0;i--) {
			if(a[i][c]!=0&&a[i][c]!=5&&a[i][c]!=2){
				return 0;
			}
			if(a[i][c]==5){
				break;
			}
		}
	}
	if(a[r][c]==2||a[r][c]==3) {
		for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) {
			if(a[i][j]!=0&&a[i][j]!=5){
				return 0;
			}
			if(a[i][j]==5){
				break;
			}
		}
		for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++) {
			if(a[i][j]!=0&&a[i][j]!=5){
				return 0;
			}
			if(a[i][j]==5){
				break;
			}
		}
	}
	if(a[r][c]==1) {
		for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) {
			if(a[i][j]!=0&&a[i][j]!=5&&a[i][j]!=1){
				return 0;
			}
			if(a[i][j]==5){
				break;
			}
			//hiii;
		}
		for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++) {
			if(a[i][j]!=0&&a[i][j]!=5&&a[i][j]!=1){
				return 0;
			}
			if(a[i][j]==5){
				break;
			}
		}
	}
	return 1;
}
void sol(int **a,int r) {
	if(r>=n) {
		cuu++;
		return;
	}
	for(int c=0;c<n;c++) {
		if(a[r][c]==0) {
			int md=abs(r-mx)+abs(c-my);
			if(md%3==0) {
				a[r][c]=1;
			} else if(md%3==1) {
				a[r][c]=2;
			} else {
				a[r][c]=3;
			}
			if(chee(a,r,c)) {
				sol(a,r+1);
			}
			//back track
			a[r][c]=0;
		}
	}
}
int main() {
	int ro=0,bi=0,qu=0;
	scanf("%d",&n);
	int **a=(int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++) {
		a[i]=(int *)calloc(n,sizeof(int));
	}
	scanf("%d",&w);
	for(int i=0;i<w;i++) {
		scanf("%d %d",&wx,&wy);
		a[wx][wy]=5;
	}
	scanf("%d %d",&mx,&my);
	sol(a,0);
	printf("%d\n",cuu);
	for(int i=0;i<n;i++) {
		free(a[i]);
	}
	free(a);
	return 0;
}
