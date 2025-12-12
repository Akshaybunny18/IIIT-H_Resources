/* 
 * Lab 3D Problem 2
 */
#include<stdio.h>

int main(){
	char a[8][8],w;
	int c=0,p=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){ 
			scanf(" %c",&a[i][j]);
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
		if(a[i][j]=='K'){
			if (i+1<8 && j-2>=0){
				if(a[i+1][j-2]=='K'){
					c=1;
				}
				if(a[i+1][j-2]=='P'){
					p=1;
				}
			}
			if (i+1<8 && j+2<8){
				if(a[i+1][j+2]=='K'){
					c=1;
				}
				if(a[i+1][j+2]=='P'){
					p=1;
				}
			}
			if (i-1>=0 && j-2>=0){
				if(a[i-1][j-2]=='K'){
					c=1;
				}
				if(a[i-1][j-2]=='P'){
					p=1;
				}
			}
			if (i-1>=0 && j+2<8){
				if(a[i-1][j+2]=='K'){
					c=1;
				}
				if(a[i-1][j+2]=='P'){
					p=1;
				}
			}
			if (j+1<8 && i-2>=0){
				if(a[i-2][j+1]=='K'){
					c=1;
				}
				if(a[i-2][j+1]=='P'){
					p=1;
				}
			}
			if (j+1<8 && i+2<8){
				if(a[i+2][j+1]=='K'){
					c=1;
				}
				if(a[i+2][j+1]=='P'){
					p=1;
				}
			}
			if (j-1>=0 && i-2>=0){
				if(a[i-2][j-1]=='K'){
					c=1;
				}
				if(a[i-2][j-1]=='P'){
					p=1;
				}
			}
			if (j-1>=0 && i+2<8){
				if(a[i+2][j-1]=='K'){
					c=1;
				}
				if(a[i+2][j-1]=='P'){
					p=1;
				}
			}
		}
		}
	}
	if(c==1){
	printf("1");}
	else if(p==1){
	printf("2");}
	if(p!=1 && c!=1){
	printf("3");}
    return 0;
} 
