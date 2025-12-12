#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *reverse(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* appendnode(struct Node* head, int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        return newnode;
    }
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newnode;
    return head;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    struct Node* head1 = NULL;
    int x;
    for (int i = 1; i < b; i++) {
        scanf("%d", &x);
        head1 = appendnode(head1, x);
    }
    while (head1 != NULL) {
        printf("%d ", head1->data);
        head1 = head1->next;
    }

    head1 = NULL;
    for (int i = b; i <= c; i++) {
        scanf("%d", &x);
        head1 = appendnode(head1, x);
    }
    head1 = reverse(head1);
    while (head1 != NULL) {
        printf("%d ", head1->data);
        head1 = head1->next;
    }

    head1 = NULL;
    for (int i = c + 1; i <= a; i++) {
        scanf("%d", &x);
        head1 = appendnode(head1, x);
    }
    while (head1 != NULL) {
        printf("%d ", head1->data);
        head1 = head1->next;
    }

    return 0;
}
