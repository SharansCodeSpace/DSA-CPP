// Stack operations
// By Sharaneshwar Bharat Punjal
// Roll No. 82, CM3I

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

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

void push(struct stack *ptr)
{
    int value;
    printf("\nEnter value to be pushed: ");
    scanf("%d", &value);
    if (isFull(ptr))
    {
        printf("Stack Overflow!\nCannot push %d to the stack..\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d pushed into the stack at position %d..\n", value, ptr->top + 1);
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\nCannot pop from the stack..\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        printf("Popped the element %d from position %d in the stack..\n", value, ptr->top + 1);
        ptr->top--;
    }
}

void peek(struct stack *ptr)
{
    printf("\nEnter the position to peek: ");
    int i;
    scanf("%d", &i);
    int index = ptr->top - i + 1;
    if (index < 0)
        printf("Not a valid position for the stack\n");
    else
        printf("The value %d is present at position %d in the stack..\n", ptr->arr[index], i);
}

void printstack(struct stack *ptr)
{
    int temp = ptr->top;
    if (isEmpty(ptr))
    {
        printf("\nStack is empty..\n");
    }
    else
    {
        printf("\nElements in the stack from top to bottom:\n");
        while (temp >= 0)
        {
            printf("%d\n", ptr->arr[temp]);
            temp--;
        }
    }
}

void main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("\n--Stack Operations--");
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Peek");
    printf("\n4. Print stack");
    printf("\n5. Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            peek(s);
            break;
        case 4:
            printstack(s);
            break;
        case 5:
            printf("\nThank you..\n\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice..\nEnter again..\n");
        }
    } while (1);
}