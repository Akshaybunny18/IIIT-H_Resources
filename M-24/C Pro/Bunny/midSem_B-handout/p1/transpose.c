// transposeArray.c

#include <stdio.h>

// Function prototype for transposing the array
int temp;
void transposeArray(int **array, int n, int row, int col)
{	if(row==n-1 && col==n-1){
		return ;}
		//printf("h");	
	temp=array[row][col];
	array[row][col]=array[col][row];
	array[col][row]=temp;
	//if(row<n-1)
	{   if(col<row){
	   col+=1;}
	    else{
		row+=1;
		col=0;
		}
	}
	transposeArray(array,n,row,col);
	}
	  // write your code here for transposing the array

