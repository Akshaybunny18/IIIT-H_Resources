#include "functions.h"
extern int op3;
void reverseString(char* str, int length){
    for(int i=0;i<length/2;i++){
        char temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}
char* compressString(char* str, int length){
    int count=1;
    char* result = (char*)malloc(2*length*sizeof(char));
    int hi=0;
    for (int i = 0; i < length; i++) {
        if (i < length - 1 && str[i] == str[i + 1]) {
            count++;
        } else {
            result[hi++] = str[i];
            if(count<10) result[hi++] = count + '0';
            else if(count<100){
                result[hi++] = count/10 + '0';
                result[hi++] = count%10 + '0';
            }
            else if(count<1000){
                result[hi++] = count/100 + '0';
                result[hi++] = (count/10)%10 + '0';
                result[hi++] = count%10 + '0';
            }
            else if(count<10000){
                result[hi++] = count/1000 + '0';
                result[hi++] = (count/100)%10 + '0';
                result[hi++] = (count/10)%10 + '0';
                result[hi++] = count%10 + '0';
            }
            else if(count==10000){
                result[hi++] = '1';
                result[hi++] = '0';
                result[hi++] = '0';
                result[hi++] = '0';
                result[hi++] = '0';
            }
            count = 1;
        }
    }
    result = (char*)realloc(result,(hi+1)*sizeof(char));
    result[hi] = '\0';
    return result;
}
int* uniqueElements(int* arr, int length){
    if(length==0){
        return NULL;
    }
    int* result = (int*)malloc(length*sizeof(int));
    int resultindex=0;
    for (int i=0;i<length;i++){
        int j=0;
        for(j=0;j<resultindex;j++){
            if(arr[i]==result[j]){
                break;
            }
        }
        if(j==resultindex){
            result[resultindex] = arr[i];
            resultindex++;
        }
    }
    op3 = resultindex;
    result = (int*)realloc(result,(resultindex)*sizeof(int));
    return result;
}
int** transpose(int** matrix, int Numrow, int Numcol){
    int** result = (int **)malloc(Numcol*sizeof(int*));
    for(int i=0;i<Numcol;i++){
        result[i] = (int*)malloc(Numrow*sizeof(int));
        for(int j=0;j<Numrow;j++){
            result[i][j] = matrix[j][i];
            //printf("%d ",result[i][j]);
        }
        //printf("\n");
    }
    // for(int i=0;i<Numcol;i++){
    //     for(int j=0;j<Numrow;j++){
    //         printf("%d ",result[i][j]);
    //     }
    //     printf("\n");
    // }
    // for(int i=0;i<Numcol;i++){
    //     free(result[i]);
    // }
    // free(result);
    return result;
}
