#include <stdio.h>
#define MAX 50

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

// Enqueue operation
void enqueue(int x)
{
    s1[++top1] = x;
    printf("Enqueued: %d\n", x);
}

// Dequeue operation
void dequeue()
{
    int i;

    // If both stacks are empty
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    // If stack2 is empty, move elements from stack1
    if (top2 == -1)
    {
        while (top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    printf("Dequeued: %d\n", s2[top2--]);
}

// Display queue
void display()
{
    int i;

    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    // Stack2 elements
    for (i = top2; i >= 0; i--)
        printf("%d ", s2[i]);

    // Stack1 elements
    for (i = 0; i <= top1; i++)
        printf("%d ", s1[i]);

    printf("\n");
}

int main()
{
    int ch, x;

    while (1)
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;
        }
    }
}
