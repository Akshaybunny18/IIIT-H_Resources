#include"main.h"

// Structure of the node of the linked list is:

/*struct node {
    int val;
    struct node *next;
};*/


struct node * sortLL(int len, struct node *head) {
    // write your code here
    //akshay;
    int c=0;
    struct node* head1 = head;
    struct node* head2=NULL;
   while(c!=len-1) {
        if(head1->next==NULL) {
            head1=head;
            head2=NULL;
            c=0;
        } 
        if(head1->val>head1->next->val) {
            struct node* dimpi=head1->next;
            head1->next=dimpi->next;
            dimpi->next=head1;

            if(head2==NULL) {
                head=dimpi;
            } else {
                head2->next=dimpi;
            }
            head2=dimpi;
        } 
        else {
            head2=head1;
            head1=head1->next;
            c++;
        }
    }
    return head;
}