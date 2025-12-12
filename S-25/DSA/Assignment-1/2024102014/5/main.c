#include "functions.h"
int n;
Row* head1end ;
Row* head2end ;
Row* head1;
Row* head2;
Row *phead=NULL;
Row *pheadend=NULL;
int cc=-1;
int main(){
    char hi[4];
    scanf("%s",hi);
    head1 = (Row*)malloc(sizeof(Row));
    head1end = head1;
    head2 = (Row*)malloc(sizeof(Row));
    head2end = head2;
    phead = (Row*)malloc(sizeof(Row));
    pheadend = phead;
    if(hi[0]=='T'){
        int row,col,l1;
        scanf("%d %d %d",&row,&col,&l1);
        int a=0,b=0,val;
        int aa=-1;
        n=l1;
        for(int i=0;i<l1;i++){
            scanf("%d %d %d",&a,&b,&val);
            if(a!=aa){
                appendRow(&head1end,NULL,a);
            }
            append(head1end,val,b,a);
            aa = a;
        }
        printf("%d\n",n);
        tra(head1,row,col);
    }
    if(hi[0]=='A'){
        int row,col,l1,l2;
        scanf("%d %d %d %d",&row,&col,&l1,&l2);
        //printf("%d %d %d %d\n",row,col,l1,l2);
        n=l1+l2;
        int a=0,b=0,val,valU;
        int aa=-1,bb=-1;
        for(int i=0;i<l1;i++){
            scanf("%d %d %d",&a,&b,&val);
            //printf("ROW1 : %d %d %d\n",a,b,val);
            if(a!=aa){
                appendRow(&head1end,NULL,a);
            }
            append(head1end,val,b,a);
            aa = a;
        }
        aa = -1;
        for(int i=0;i<l2;i++){
            scanf("%d %d %d",&a,&b,&valU);
            //printf("ROW2 :%d %d %d\n",a,b,valU);
            if(a!=aa){
                appendRow(&head2end,NULL,a);
            }
            append(head2end,valU,b,a);
            aa = a;
        }
        //printf("---------");
        // printAll(head1);
        // printf("---------");
        // printAll(head2);
        // printf("---------");
        add(head1,head2,row,col);
        //printf("---------");
        printf("%d\n",n);
        printAll(phead);
        //printf("end");
    }
    if(hi[0]=='M'){
        int row,colrow,col,l1,l2;
        scanf("%d %d %d %d %d",&row,&colrow,&col,&l1,&l2);
        int a=0,b=0,val;
        int aa=-1,bb=-1;
        for(int i=0;i<l1;i++){
            scanf("%d %d %d",&a,&b,&val);
            if(a!=aa){
                appendRow(&head1end,NULL,a);
            }
            append(head1end,val,b,a);
            aa = a;
        }
        aa = -1;
        for(int i=0;i<l2;i++){
            scanf("%d %d %d",&a,&b,&val);
            if(a!=aa){
                appendRow(&head2end,NULL,a);
            }
            append(head2end,val,b,a);
            mul(head1,head2,row,colrow,col); 
        }
    }
    freeRow(head1);
    freeRow(head2);
    return 0;
}
