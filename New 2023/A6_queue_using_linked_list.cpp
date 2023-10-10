#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

bool isEmpty()
{
    return front == NULL && rear == NULL;
}

void enqueue(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (isEmpty())
        front = rear = ptr;
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void display()
{
    if (isEmpty())
        cout << "Queue is empty!" << endl;
    else
    {
        struct Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int dequeue()
{
    int data = -1;
    if (isEmpty())
        cout << "Queue is empty!" << endl;
    else
    {
        struct Node *temp = front;
        data = temp->data;
        front = front->next;
        free(temp);
    }
    return data;
}

int peek()
{
    return front->data;
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