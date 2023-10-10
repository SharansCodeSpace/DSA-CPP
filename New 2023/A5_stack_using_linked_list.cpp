#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = top;
    top = ptr;
}

int pop()
{
    int data = -1;
    if (top == NULL)
        cout << "Stack is Empty!" << endl;
    else
    {
        struct Node *temp = top;
        data = temp->data;
        top = top->next;
        free(temp);
    }
    return data;
}

int peek()
{
    return top->data;
}

void display()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    cout << pop() << endl;
    cout << peek() << endl;
    display();
    return 0;
}