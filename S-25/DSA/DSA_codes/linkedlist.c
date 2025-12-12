#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL, *headend = NULL;

Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(int data) {
    Node *new_node = create_node(data);
    if (!head) head = headend = new_node;
    else headend = headend->next = new_node;
}

void insert_at_front(int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    if (!headend) headend = head;
}

void insert_at_index(int index, int data) {
    if (index == 0) {
        insert_at_front(data);
        return;
    }
    Node *cur = head;
    while (--index && cur) cur = cur->next;
    if (!cur) return;
    Node *new_node = create_node(data);
    new_node->next = cur->next;
    cur->next = new_node;
    if (!new_node->next) headend = new_node;
}

void delete_node(int data) {
    if (!head) return;
    if (head->data == data) {
        Node *temp = head;
        head = head->next;
        if (!head) headend = NULL;
        free(temp);
        return;
    }
    Node *cur = head;
    while (cur->next && cur->next->data != data) cur = cur->next;
    if (!cur->next) return;
    Node *temp = cur->next;
    cur->next = cur->next->next;
    if (!cur->next) headend = cur;
    free(temp);
}

int main(){
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert_node(data);
    }
    insert_at_front(10);
    insert_at_index(2, 20);
    delete_node(20);
    Node *cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 0;
}