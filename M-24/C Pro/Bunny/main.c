#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x=9;
void printarray(int a[][x]){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int check(int a[][x]){
    // check if the current solution is valid
    // return if any 0 present in the matrix include check row in this cases itself 
    //chec row
    for(int i = 0; i < x; i++){
        int row[x];
        for(int j = 0; j < x; j++){
            row[j] = 0;
        }
        for(int j = 0; j < x; j++){
            if(a[i][j] != 0){
                row[a[i][j] - 1]++;
            }
        }
        for(int j = 0; j < x; j++){
            if(row[j] > 1){
                return 0;
            }
        }
    }
    //check column
    for(int i = 0; i < x; i++){
        int col[x];
        for(int j = 0; j < x; j++){
            col[j] = 0;
        }
        for(int j = 0; j < x; j++){
            if(a[j][i] != 0){
                col[a[j][i] - 1]++;
            }
        }
        for(int j = 0; j < x; j++){
            if(col[j] > 1){
                return 0;
            }
        }
    }
    //check subgrid
    for(int i = 0; i < x; i += 3){
        for(int j = 0; j < x; j += 3){
            int subgrid[x];
            for(int k = 0; k < x; k++){
                subgrid[k] = 0;
            }
            for(int k = i; k < i + 3; k++){
                for(int l = j; l < j + 3; l++){
                    if(a[k][l] != 0){
                        subgrid[a[k][l] - 1]++;
                    }
                }
            }
            for(int k = 0; k < x; k++){
                if(subgrid[k] > 1){
                    return 0;
                }
            }
        }
    }
    return 1;
}
void suodoku( int a[][x]){
    //should print all possible valid solutions
    if(check(a)){
        printarray(a);
    }
    else{
        for(int i = 0; i < x; i++){
            for(int j = 0; j < x; j++){
                if(a[i][j] == 0){
                    for(int k = 1; k <= x; k++){
                        a[i][j] = k;
                        suodoku(a);
                        a[i][j] = 0;
                    }
                    return;
                }
            }
        }
    }
    
}
int main(){
    int a[x][x];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            //scanf("%d", &a[i][j]);
            a[i][j] = 0;
        }
    }
    suodoku(a);
    return 0;
}