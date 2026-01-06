#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

int main()
{
    head = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter your data");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = temp = newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }

    temp=head;
    while(temp!=0)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
