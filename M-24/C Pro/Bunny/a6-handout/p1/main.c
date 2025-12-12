/*
 Assignment 6 problem 1
*/

#include <stdio.h>

int main(){
    FILE *fptr;
    char dna[200000];
    int i = 0;
    fptr = fopen("dna.txt", "r");
    FILE *fptr2;
    fptr2 = fopen("codon.txt", "r");
    char c;
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    rewind(fptr);
    fseek(fptr, 0, SEEK_SET);
    while(ftell(fptr)<size){
        c = fgetc(fptr);
        if (c == 'A') dna[i++] = 'T';  
        else if (c == 'T') dna[i++] = 'A'; 
        else if (c == 'C') dna[i++] = 'G';  
        else if (c == 'G') dna[i++] = 'C'; 
        c='q';
    }
    dna[i] = '\0';
    //printf("\n%s\n", dna);
    int j=0;
    while(dna[j]!='\0'){
        if(dna[j]=='T'){
            dna[j] = 'U';
        }
        j++;
    }
    //printf("%s\n", dna);
    char codon[5];
    int p=1;
    char arr[64][3];
    char arr2[64];
    while(p<65){
        fscanf(fptr2, "%3s", codon);
        codon[3]=fgetc(fptr2);
        codon[4]=fgetc(fptr2);
        arr[p-1][0]=codon[0];
        arr[p-1][1]=codon[1];
        arr[p-1][2]=codon[2];
        arr2[p-1]=codon[4];
        p++;
    }
    /////traver
    int q = 0;
    char a, b, cc;
    int u = 0;
    i=0;
    for(int xx=0;xx<3; xx++){
    i=xx;
    int z=0;
    int v=0;
    while (dna[i] != '\0' && dna[i + 1] != '\0' && dna[i + 2] != '\0') {
        a = dna[i];
        b = dna[i + 1];
        cc = dna[i + 2];
        if(a=='A' && b=='U' && cc=='G' || z==1){
            z=1;
            u++;
            for(int j=0;j<64;j++){
                if(a==arr[j][0] && b==arr[j][1] && cc==arr[j][2]){
                    if(arr2[j]=='_'){
                        printf("\n");
                        z=0;
                    }
                    else{
                        printf("%c",arr2[j]);
                        v=1;
                    }
                    break;
                }
            }
        }
        i+=3;
    }
    if(v!=0) printf("\n");
    }
    if(u==0) printf("NA");
    return 0;
}