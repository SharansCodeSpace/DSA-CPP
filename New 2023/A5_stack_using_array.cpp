#include <iostream>
using namespace std;

int n = 100;
int top = -1;
int arr[100];

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == n - 1;
}

void push(int val)
{
    if (top == n - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        arr[top] = val;
    }
}

int pop()
{
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
        return arr[top--];
}

int peek() 
{
    return arr[top];
}

void display()
{
    if (isEmpty())
        cout << "Stack is Empty" << endl;
    else
    {
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    display();
    cout << pop() << endl;
    cout << peek() << endl;
    display();
    return 0;
}