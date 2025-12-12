void recursion(struct node **head, int *x) 
{
    struct node *front = NULL, *temp = *head, *prev = NULL;
    int counter = 0;
    
    while (counter < *x && temp != NULL)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
        counter++;
    }

    *x *= 2;

    if (front != NULL)
    {
        (*head)->next = front;
        recursion(&front, x);
    }

    *head = prev;
}

struct node *reverseingroups(struct node *head)
{
    int x = 2;
    recursion(&head, &x);
    return head;
}

