#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch)
{
    stack[++top] = ch;
}

// Pop operation
char pop()
{
    return stack[top--];
}

int main()
{
    char str[MAX];
    int i;

    printf("Enter a string: ");
    gets(str);

    // Push all characters onto stack
    for (i = 0; str[i] != '\0'; i++)
        push(str[i]);

    // Pop characters back to string
    for (i = 0; str[i] != '\0'; i++)
        str[i] = pop();

    printf("Reversed string: %s\n", str);

    return 0;
}
