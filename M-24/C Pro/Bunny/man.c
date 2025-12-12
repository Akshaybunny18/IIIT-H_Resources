#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int x;
void print(int a[][x]){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
//write a function to check if the newly placed number is valid  is valid or not
// int j is for ?  int k is for ? 
// int i is for row number
// int j is for column number
// int k is for the number to be placed

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

int cheek(int a[][x],int i, int j, int k){
    //check row
    for(int l = 0; l < x; l++){
        if(a[i][l] == k){
            return 0;
        }
    }
    //check column
    for(int l = 0; l < x; l++){
        if(a[l][j] == k){
            return 0;
        }
    }
    //check subgrid
    int m = i / 3;
    int n = j / 3;
    for(int l = m * 3; l < m * 3 + 3; l++){
        for(int o = n * 3; o < n * 3 + 3; o++){
            if(a[l][o] == k){
                return 0;
            }
        }
    }
    return 1;
}

int q=0;
void suku(int a[][x]){
    //should print all possible valid solutions
    //const int q = 3;
    if(q==x*x){
        if(check(a)){
            print(a);
        }
    }
    else{
        for(int i = 0; i < x; i++){
            for(int j = 0; j < x; j++){
                if(a[i][j] == 0){
                    for(int k = 1; k <= x; k++){
                        if(cheek(a, i, j, k)){
                            q++;
                            a[i][j] = k;
                            suku(a);
                            a[i][j] = 0;
                        }
                        else{
                            q=0;
                        }
                    }
                    return;
                }
            }
        }
    }
    
}

int main(){
    scanf("%d", &x);
    int a[x][x];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            a[i][j] = 0;
            //scanf("%d", &a[i][j]);
        }
    }   
    suku(a);
    return 0;
}