/* 
 * Lab 2 Problem 3
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m,sum=0;
    scanf("%d", &n);
    scanf("%d", &m);
    int matrix[n][m];
    
 for (int i=0;i<n;i++){
 	for(int j=0;j<m;j++){
 		scanf("%d",&matrix[i][j]);
 	}
 }
int i=0,j=0;
	while(i<n && j<m){
		if (i==n-1 && j==m-1){
			break;
		}
		if (i==n-1){
			sum=sum+matrix[i][j+1];
			j++;
		}
		else if (j==m-1){
			sum=sum+matrix[i+1][j];
			i++;
		}
		else if(matrix[i+1][j]<matrix[i][j+1]){
	 		sum=sum+matrix[i+1][j];
	 		i++ ;
	 	}
	 	else if (matrix[i][j+1]<matrix[i+1][j])  {
	 		sum=sum+matrix[i][j+1];
	 		j++ ;
	 	}
	}
	printf("%d",sum+matrix[0][0]);

    

    
    // write your code here




    
    // Free-ing the dynamically allocated memory
    return 0;
} 
