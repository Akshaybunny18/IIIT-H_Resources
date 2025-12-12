#include <stdio.h>
void main(){
	int a[9][9],b[9],c[9],d[9],e[9],f[9],g[9],h[9],i[9],j[9];
	for (int z=0;z<9;z++){
		for (int x=0;x<9;x++){
			scanf("%d",&b[x]);
		}
		for(int w=0;w<9;w++){
			a[z][w]=b[w];
		}
	}
	int y=0;
	for (int m=0;m<9;m++){
		for(int n=0;n<9;n++){
			for(int o=0;o<9;o++){
				if(a[m][n]==a[o][n]){
					y=y+1;
				}
			}
			for(int p=0;p<9;p++){
				if(a[m][n]==a[m][p]){
					y=y+1;
				}
			}	

		}
	
	}
	if (y==162){
		printf("1");
	}
	else {
		printf("0");
	}
}
