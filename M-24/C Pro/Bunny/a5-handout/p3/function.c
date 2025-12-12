#include "main.h"
/*struct node {
    char name[11];
    struct node *next;
};*/

void recursion(struct node** head1, int x) { 
    // pass your parameters
    // write your code here
    struct node* bef = NULL;
    struct node* head0 = *head1;
    struct node* next = NULL;
    //int addition = 0;
    for (int add = 0; add < x && head0; add++) {
        next = head0->next;
        head0->next = bef;
        bef = head0;
        head0 = next;
    }
    if (next) {
        recursion(&next, x * 2);
          (*head1)->next = next; // attaching list new + old
    } else {
        (*head1)->next = NULL; // Ensure the last node's next pointer is NULL
    }
    *head1=bef;
}

struct node * reverseingroups(struct node* head) {
    // write your code here
    // recursion()
    int x = 2;
    recursion(&head, x);
    return head; 
}
