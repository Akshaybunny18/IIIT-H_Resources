#include "functions.h"
int op3=0;
int main(){
    int iter;
    scanf("%d",&iter);
    for(int l=0;l<iter;l++){ 
        //printf("buuuuuuuuu");
        char inp[5];
        scanf("%s",inp);
        /*e*/if(inp[4]=='1'){
            int length;
            scanf("%d",&length);
            char str[length];
            scanf("%s",str);
            reverseString(str,length);
            printf("%s\n",str);
        }
        //printf("hiii");
        if(inp[4]=='2'){
            int length;
            scanf("%d",&length);
            char str[length];
            scanf("%s",str);
            char* cs = compressString(str,length);
            printf("%s\n",cs);
            free(cs);
        }
        else if(inp[4]=='3'){
            int length;
            scanf("%d",&length);
            int arr[length];
            for(int i=0;i<length;i++){
                scanf("%d",&arr[i]);
            }
            int* result = uniqueElements(arr,length);
            if(result==NULL){
                printf("NULL\n");
                continue;
            }
            else{
                for(int a=0;a<op3;a++){
                    printf("%d ",result[a]);
                }
                printf("\n");
                free(result);
            }
            op3=0;
        }
        else if(inp[4]=='4'){
            int Numrow,Numcol;
            scanf("%d %d",&Numrow,&Numcol);
            int **matrix = (int**)malloc(Numrow*sizeof(int*));
            for(int i=0;i<Numrow;i++){
                matrix[i] = (int*)malloc(Numcol*sizeof(int));
                for(int j=0;j<Numcol;j++){
                    scanf("%d",&matrix[i][j]);
                }
            }
            int ** result = transpose(matrix,Numrow,Numcol);
            //print result
            for(int i=0;i<Numcol;i++){
                for(int j=0;j<Numrow;j++){
                    printf("%d ",result[i][j]);
                }
                printf("\n");
            }
            for(int i=0;i<Numcol;i++){
                free(result[i]);
            }
            for(int i=0;i<Numrow;i++){
                free(matrix[i]);
            }
            free(matrix);
        }
        else{
            continue;
        }
        //printf("Iteration %d: Input is %s\n", l+1, inp);
    }
    return 0;
}
