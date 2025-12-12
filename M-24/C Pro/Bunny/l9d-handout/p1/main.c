// Must create a struct called Vector

/*
 Lab 9B problem 1
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    char user[100];
    char** stock;
    int *stockp;
};

int main()
{
    // write your code here
    struct data *port = malloc(1000 * sizeof(struct data));
    char sto[110][10];
    float stor[110]={0};
    FILE *file;
    file=fopen("file.txt","r");
    char vud1[1000]={0};
    char vud[1000]={0};
    //struct data port[100];
    int n=0;
    int s=0;
    int c=0;
    float cc=0;
    int flag=0;
    int flagg=0;
    int st=0;
    int b=0;
    char hi[10]={0};
    for (int i = 0; i < 1000; i++){
        port[i].stock = (char**) malloc(100 * sizeof(char*));
        for (int j = 0; j < 100; j++){
            port[i].stock[j] = (char*) malloc(50 * sizeof(char));
            memset(port[i].stock[j], 0, 50 * sizeof(char));
        }
        port[i].stockp = malloc(100 * sizeof(int));
        memset(port[i].stockp, 0, 100 * sizeof(int));
    }
    while(fscanf(file,"%s",hi)==1){
        flag=0;
        flagg=0;
        st=0;
        b=0;
        //printf("%s\n",hi);
        if(strcmp(hi,"AddUser")==0){
            fscanf(file,"%s",vud);
            for(int q=0;q<n;q++){
                if(strcmp(vud,port[q].user)==0){
                    printf("User %s already exists.\n", vud);
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                strcpy(port[n].user,vud);
                n++;
                continue;
            }
            else
                continue;
        }
        if(strcmp(hi,"AddStock")==0){
            fscanf(file,"%s %f",vud,&cc);
            for(int q=0;q<s;q++){
                if(strcmp(vud,sto[q])==0){
                    printf("Stock %s already exists.\n", vud);
                    st=1;
                    break;
                }
            }
            if(st==0){
                strcpy(sto[s],vud);
                stor[s]=cc;
                //printf("Stock %s added with price %.2f.\n", vud, cc);
                s++;
            }
            continue;
        }
        if(strcmp(hi,"Buy")==0){
            fscanf(file,"%s %s %d",vud,vud1,&c);
            for(int q=0;q<s;q++){
                if(strcmp(vud1,sto[q])==0){
                    st=1;
                    break;
                }
            }
            if(st==0){
                printf("Stock %s does not exist.\n", vud1);
                continue;
            }
            for(int q=0;q<n;q++){
                if(strcmp(vud,port[q].user)==0){
                    flag=1;
                    int z=0;
                    while(port[q].stockp[z]!=0){
                        if(strcmp(vud1,port[q].stock[z])==0){
                            b=1;
                            // if(port[q].stockp[z]+c<=1000){
                                port[q].stockp[z]+=c;
                                printf("User %s bought %d shares of %s.\n",vud,c,vud1);
                                break;
                            // }
                            // else{
                            //     printf("User %s does not have enough space to buy %d shares of %s.\n", vud, c, vud1);
                            //      break;
                            // }
                        }
                        z++;
                        //printf("%dmmmmmmmm",z);
                    }
                    if(b==0){
                        //z++;
                        strcpy(port[q].stock[z],vud1);
                        port[q].stockp[z]=c;
                        //printf("%d %d\n",port[q].stockp[z],z);
                        printf("User %s bought %d shares of %s.\n",vud,c,vud1);
                    }
                }
            }
            if(flag==0){
                 printf("User %s does not exist.\n", vud);
            }
        }
        if(strcmp(hi,"Sell")==0){
            fscanf(file,"%s %s %d",vud,vud1,&c);
            //printf("%s %s %d\n",vud,vud1,c);
            for(int q=0;q<s;q++){
                if(strcmp(vud1,sto[q])==0){
                    st=1;
                    break;
                }
            }
            //printf("hjbn");
            if(st==0){
                printf("Stock %s does not exist.\n", vud1);
                continue ;
            }
            for(int q=0;q<n;q++){
                if(strcmp(vud,port[q].user)==0){
                    flag=1;
                    //printf("%d-----------------",port[q].stockp[0]);
                    for(int z=0;port[q].stockp[z]>0;z++){
                        if(strcmp(vud1,port[q].stock[z])==0){
                            flagg=1;
                            if(port[q].stockp[z]<c){
                                //printf("%d %d\n",port[q].stockp[z],c);
                                printf("User %s does not have enough shares of %s to sell.\n", vud, vud1);
                            }
                            else{
                                port[q].stockp[z]-=c;
                                printf("%s sold %d shares of %s.\n",vud,c,vud1);
                            }
                            break;
                        }
                    }
                }
            }
            if(flag==0){
                 printf("User %s does not exist.\n", vud);
            }
            else if(flagg==0){
                 printf("User %s does not have enough shares of %s to sell.\n", vud, vud1);
            }
        }
        if(strcmp(hi,"Portfolio")==0){
            fscanf(file,"%s",vud);
            for(int q=0;q<n;q++){
                if(strcmp(vud,port[q].user)==0){
                    printf("Portfolio for %s:\n",vud);
                    for(int z=0;port[q].stockp[z]!=0;z++){
                        for(int y=0;y<s;y++){
                            if(strcmp(port[q].stock[z],sto[y])==0){
                                printf("Stock: %s, Shares: %d, Total Value: %.2f\n", port[q].stock[z], port[q].stockp[z],port[q].stockp[z]*stor[y]);                            }
                        }
                    }
                }                
            }
        }
        if(strcmp("List",hi)==0){
            for(int q=0;q<s;q++){
                printf("Stock: %s, Price: %.2f\n",sto[q],stor[q]);
            }
        }
    }
    for(int i=0;i<1000;i++){
        free(port[i].stock);
        free(port[i].stockp);
    }
    free(port);
    fclose(file);
    return 0;
}