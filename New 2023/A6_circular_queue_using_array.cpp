#include <iostream>
using namespace std;

const int n = 100;
int queue[n];
int front = -1, rear = -1;

bool isEmpty()
{
    return front == -1 && rear == -1;
}

bool isFull()
{
    return (rear + 1) % n == front;
}

void enqueue(int data)
{
    if (isFull())
        cout << "Queue Overflow" << endl;
    else if (isEmpty())
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear = (rear + 1) % n;
        queue[rear] = data;
    }
}

int dequeue()
{
    int data = -1;
    if (isEmpty())
        cout << "Queue Underflow" << endl;
    else if (front == rear)
    {
        data = queue[front];
        front = rear = -1;
    }
    else
    {
        data = queue[front];
        front = (front + 1) % n;
    }
    return data;
}

void display()
{
    if (isEmpty())
        cout << "Queue Underflow" << endl;
    else
    {
        for (int i = front; i != rear; i = (i + 1) % n)
            cout << queue[i] << " ";
        cout << queue[rear] << endl;
    }
}

int peek()
{
    return queue[front];
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    cout << dequeue() << endl;
    cout << peek() << endl;
    enqueue(60);
    display();
    return 0;
}