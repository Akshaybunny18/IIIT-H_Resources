#include "functions.h"
extern Row* head1end ;
extern Row* head2end ;
extern Row* head1;
extern Row* head2;
extern Row *phead;
extern Row *pheadend;
extern int cc;
extern int n;
void append(Row *rowend, int element, int column, int row){
    //printf("APPEND : %d %d %d\n",row,column,element);
    PtrNode* new = (PtrNode*)malloc(sizeof(PtrNode));
    new->Element = element;
    new->Column = column;
    new->Row = row;
    new->NextNode = NULL;
    if(rowend->end==NULL){
        rowend->end = new;
        rowend->Col = new;
        return;
    }
    rowend->end->NextNode = new;
    rowend->end = new;
}
void appendRow(Row** headend, PtrNode* head, int row){
    Row* new = (Row*)malloc(sizeof(Row));
    new->rowNum = row;
    new->Col = head;
    new->next = NULL;
    new->end = head;
    if(*headend==NULL){
        *headend = new;
        return;
    }
    (*headend)->next = new;
    *headend = new;
}
void append1(int element, int column, int row){
    if(cc!=row){
        appendRow(&pheadend,NULL,row);
    }
    append(pheadend,element,column,row);
    cc = row;
    //printf("phead: %p pheadend : %p\n",phead,pheadend);
}
void printRow(Row* head){
    PtrNode* temp = head->Col;
    //printf("temp : %p\n",temp);
    while(temp!=NULL){
        //printf("col : %p-- ",temp);
        printf("%d %d %d\n",temp->Row,temp->Column,temp->Element);
        temp = temp->NextNode;
    }
}
void printAll(Row* head){
    Row* temp = head;
    //printf("ROW : %p\n",temp);
    while(temp!=NULL){
        //printf("ROW : %p\n",temp);
        printRow(temp);
        temp = temp->next;
    }
}
void add(Row* head1, Row* head2, int row, int col){
    int i=0,j=0;
    Row* tem1 = head1;
    Row* tem2 = head2;
    //printf("000000000");
    tem1=tem1->next;
    tem2=tem2->next;
    //printf("tem1pointer : %p\n",tem1);
    //printf("tem2pointer : %p\n",tem2);
    //printf("head1pointer : %p\n",head1->Col);
    //printf("head2pointer : %p\n",head2->Col);
    PtrNode* temp1 = (tem1!=NULL)?tem1->Col:NULL;
    PtrNode* temp2 = (tem2!=NULL)?tem2->Col:NULL;
    //printf("temp1pointer : %p\n",temp1);
    //printf("temp2pointer : %p\n",temp2);
    while(tem1!=NULL && tem2!=NULL){
        if(tem1->rowNum==tem2->rowNum){
            while(temp1 != NULL && temp2 != NULL){
                if(temp1->Column==temp2->Column){
                    if(temp1->Element+temp2->Element==0){
                        temp1 = temp1->NextNode;
                        temp2 = temp2->NextNode;
                        n-=2;
                        continue;
                    }
                    n--;
                    append1(temp1->Element+temp2->Element,temp1->Column,temp1->Row);
                    //printf("%d %d %d\n",temp1->Row,temp1->Column,temp1->Element+temp2->Element);
                    temp1 = temp1->NextNode;
                    temp2 = temp2->NextNode;
                }
                else if(temp1->Column<temp2->Column ){
                    append1(temp1->Element,temp1->Column,temp1->Row);
                    //printf("%d %d %d\n",temp1->Row,temp1->Column,temp1->Element);
                    temp1 = temp1->NextNode;
                }
                else{
                    append1(temp2->Element,temp2->Column,temp2->Row);
                    //printf("%d %d %d\n",temp2->Row,temp2->Column,temp2->Element);
                    temp2 = temp2->NextNode;
                }
            }
            while(temp1!=NULL){
                append1(temp1->Element,temp1->Column,temp1->Row);
                //printf("%d %d %d\n",temp1->Row,temp1->Column,temp1->Element);
                temp1 = temp1->NextNode;
            }
            while(temp2!=NULL){
                append1(temp2->Element,temp2->Column,temp2->Row);
                //printf("%d %d %d\n",temp2->Row,temp2->Column,temp2->Element);
                temp2 = temp2->NextNode;
            }
            tem1=(tem1!=NULL)?tem1->next:NULL;
            tem2=(tem2!=NULL)?tem2->next:NULL;
            temp1=(tem1!=NULL)?tem1->Col:NULL;
            temp2=(tem2!=NULL)?tem2->Col:NULL;
        }
        else if(tem1->rowNum<tem2->rowNum){
            while(temp1!=NULL){
                append1(temp1->Element,temp1->Column,temp1->Row);
                //printf("%d %d %d\n",temp1->Row,temp1->Column,temp1->Element);
                temp1 = temp1->NextNode;
            }
            tem1=(tem1!=NULL)?tem1->next:NULL;
            temp1=(tem1!=NULL)?tem1->Col:NULL;
        }
        else{
            while(temp2!=NULL){
                append1(temp2->Element,temp2->Column,temp2->Row);
                //printf("%d %d %d\n",temp2->Row,temp2->Column,temp2->Element);
                temp2 = temp2->NextNode;
            }
            tem2=(tem2!=NULL)?tem2->next:NULL;
            temp2=(tem2!=NULL)?tem2->Col:NULL;
        }
    }
    while(tem1!=NULL){
        while(temp1!=NULL){
            append1(temp1->Element,temp1->Column,temp1->Row);
            //printf("%d %d %d\n",temp1->Row,temp1->Column,temp1->Element);
            temp1 = temp1->NextNode;
        }
        tem1 = tem1->next;
        temp1 = (tem1!=NULL)?tem1->Col:NULL;
    }
    while(tem2!=NULL){
        while(temp2!=NULL){
            append1(temp2->Element,temp2->Column,temp2->Row);
            //printf("%d %d %d\n",temp2->Row,temp2->Column,temp2->Element);
            temp2 = temp2->NextNode;
        }
        tem2 = tem2->next;
        temp2 = (tem2!=NULL)?tem2->Col:NULL;
    }
    //printf("end");
}
void mul(Row* head1, Row* head2, int row, int colrow, int col){

}
void tra(Row* head, int row, int col){
    Row* temp = head;
    temp = temp->next;
    PtrNode* temp2 = temp->Col;
    // i need to print in in order after transposing
    //first store in an array
    struct hi arr[n];
    int i=0;
    while(temp!=NULL){
        temp2 = temp->Col;
        while(temp2!=NULL){
            arr[i].row = temp2->Column;
            arr[i].col = temp2->Row;
            arr[i].val = temp2->Element;
            i++;
            temp2 = temp2->NextNode;
        }
        temp = temp->next;
    }
    //then sort the array according to arr[].row as precedence  and arr[].col
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].row>arr[j].row){
                struct hi temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if(arr[i].row==arr[j].row){
                if(arr[i].col>arr[j].col){
                    struct hi temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    //then print the array
    for(int i=0;i<n;i++){
        printf("%d %d %d\n",arr[i].row,arr[i].col,arr[i].val);
    }
}
void freenode(PtrNode* head){
    PtrNode* temp = head;
    while(temp!=NULL){
        PtrNode* temp2 = temp;
        temp = temp->NextNode;
        free(temp2);
    }
}
void freeRow(Row* head){
    Row* temp = head;
    while(temp!=NULL){
        PtrNode* temp2 = temp->Col;
        while(temp2!=NULL){
            PtrNode* temp3 = temp2;
            temp2 = temp2->NextNode;
            free(temp3);
        }
        Row* temp3 = temp;
        temp = temp->next;
        free(temp3);
    }
}
