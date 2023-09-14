#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Return values in this function are chosen manually...Update this function if other operators are needed...
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char *infixToPrefix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *infixreverse = (char *)malloc(sp->size * sizeof(char));
    char *prefix = (char *)malloc(strlen(infix + 1) * sizeof(char));
    int i = 0;
    for (int k = strlen(infix) - 1; i < strlen(infix); k--)
    {
        if (infix[k] == '\0')
            continue;
        else
        {
            infixreverse[i] = infix[k];
            i++;
        }
    }
    infixreverse[i] = '\0';
    i = 0;
    int j = 0; // Track prefix addition
    while (infixreverse[i] != '\0')
    {
        if (!isOperator(infixreverse[i]))
        {
            prefix[j] = infixreverse[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infixreverse[i]) > precedence(stackTop(sp)))
            {
                push(sp, infixreverse[i]);
                i++;
            }
            else
            {
                prefix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        prefix[j] = pop(sp);
        j++;
    }
    prefix[j] = '\0';

    char *prefixreverse = (char *)malloc(sp->size * sizeof(char));
    i=0;
    for (int k = strlen(prefix) - 1; i < strlen(prefix); k--)
    {
        if (prefix[k] == '\0')
            continue;
        else
        {
            prefixreverse[i] = prefix[k];
            i++;
        }
    }
    return prefixreverse;
}

void main()
{
    char *infix = "a-b+t/6";
    printf("Prefix is %s\n", infixToPrefix(infix));
}