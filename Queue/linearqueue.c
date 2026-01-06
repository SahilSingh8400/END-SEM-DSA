#include <stdio.h>
#define n 5
int q[n];
int front = -1;
int rear = -1;

void enque(int x)
{
    if (rear == n - 1)
    {
        printf("overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear] = x;
    }
    else
    {
        rear++;
        q[rear] = x;
    }
}

void deque()
{
    if (front == -1 && rear == -1)
    {
        printf("pverflow");
    }
    else if (front == rear)
        front = rear = -1;
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        for (int i = 0; i < rear++; i++)
        {
            printf("%d", q[i]);
        }
    }
}