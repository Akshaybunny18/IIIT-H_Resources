#include <stdio.h>
#include <stdlib.h>
#include "transpose.c"


// Function prototype for transposing the array
// void transposeArray(int *array, int n, int row, int col);

int main() {
    int n; // array size
	
	scanf("%d",&n);
    // Input the size of the array
    int **array =(int**)malloc(n*sizeof(int*));
	for(int i=0 ;i<n;i++){
	array[i]=(int*)malloc(n*sizeof(int));
	}
//printf("h");

    // Todo: Dynamically allocate memory for the array
    

    // Todo: Input the elements of the array
    
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&array[i][j]);
			//printf("h");
		}
	}
	//printf("h");
	
    // Todo: Call the transpose function
    transposeArray(array, n, 0, 0);

    // Todo: Output the transposed array
    for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",array[i][j]);
			//printf("h");
		}
		printf("\n");
	}

    // Todo: Free allocated memory
    free(array);
    for(int i=0 ;i<n;i++){
    free(array[i]);}
    
    return 0;
}
