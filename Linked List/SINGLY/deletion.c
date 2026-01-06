#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;
    struct node *next;
};

/* Insert at beginning */
struct node* insert_beg(struct node* head, int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    return newnode;
}

/* Insert at end */
struct node* insert_last(struct node* head, int val)
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

/* Insert at any position */
struct node* insert_any(struct node* head, int val, int pos)
{
    struct node *newnode, *temp;

    if (pos == 1)
        return insert_beg(head, val);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

/* Delete from beginning */
struct node* del_start(struct node* head)
{
    struct node* temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

/* Delete from end */
struct node* del_end(struct node* head)
{
    struct node *temp, *del;

    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    del = temp->next;
    temp->next = NULL;
    free(del);
    return head;
}

/* Delete from any position */
struct node* del_any(struct node* head, int pos)
{
    struct node *temp, *del;

    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (pos == 1)
        return del_start(head);

    temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

/* Display list */
void display(struct node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Main function */
int main()
{
    struct node* head = NULL;

    head = insert_beg(head, 10);
    head = insert_beg(head, 5);
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_any(head, 15, 3);

    printf("After insertion:\n");
    display(head);

    head = del_start(head);
    printf("After delete from start:\n");
    display(head);

    head = del_end(head);
    printf("After delete from end:\n");
    display(head);

    head = del_any(head, 2);
    printf("After delete from position 2:\n");
    display(head);

    return 0;
}
