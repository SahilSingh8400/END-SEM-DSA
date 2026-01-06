#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push function */
void push(char ch) {
    stack[++top] = ch;
}

/* Pop function */
char pop() {
    return stack[top--];
}

/* Match opening and closing brackets */
int match(char open, char close) {
    if(open == '(' && close == ')') return 1;
    if(open == '{' && close == '}') return 1;
    if(open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char exp[MAX];
    int i;

    printf("Enter an expression: ");
    scanf("%s", exp);

    for(i = 0; exp[i] != '\0'; i++) {

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            if(top == -1) {
                printf("Parentheses are NOT Balanced\n");
                return 0;
            }

            char open = pop();
            if(!match(open, exp[i])) {
                printf("Parentheses are NOT Balanced\n");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("Parentheses are Balanced\n");
    else
        printf("Parentheses are NOT Balanced\n");

    return 0;
}
