#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* deleteByValue(struct Node* head, int x) {
    if (head == NULL) return head;
    if (head->data == x) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* hi = head;
    while (hi->next != NULL && hi->next->data != x) {
        hi = hi->next;
    }
    if (hi->next != NULL) {
        struct Node* temp = hi->next;
        hi->next = hi->next->next;
        free(temp);
    }
    return head;
}

struct Node* newNode(int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* new = newNode(data);
    if (head == NULL) return new;
    struct Node* hi = head;
    while (hi->next != NULL) hi = hi->next;
    hi->next = new;
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = appendNode(head, x);
    }
    scanf("%d", &value);
    head = deleteByValue(head, value);
    printList(head);
    return 0;
}
