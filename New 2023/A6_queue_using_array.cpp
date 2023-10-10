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
    return rear == n - 1;
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
        queue[++rear] = data;
    // queue[(rear + 1) % n] = data; -> For circualr queue
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
        data = queue[front++];
    // data = queue[(front + 1) % n] -> For circular queue
    return data;
}

void display()
{
    if (isEmpty())
        cout << "Queue Underflow" << endl;
    else
    {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
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
    display();
    cout << dequeue() << endl;
    cout << peek() << endl;
    display();
    return 0;
}