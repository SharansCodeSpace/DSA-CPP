#include <iostream>
using namespace std;

class Deque
{
private:
    int *array;
    int front;
    int rear;
    int size;

public:
    Deque(int size)
    {
        this->size = size;
        this->array = new int[size];
        this->front = -1;
        this->rear = 0;
    }

    ~Deque()
    {
        delete[] array;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || front == rear + 1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void insertFront(int item)
    {
        if (isFull())
        {
            cout << "Deque is full" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        array[front] = item;
    }

    void insertRear(int item)
    {
        if (isFull())
        {
            cout << "Deque is full" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        array[rear] = item;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }

    void traverse()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return;
        }

        for (int i = front; i != rear; i = (i + 1) % size)
        {
            cout << array[i] << " ";
        }
        cout << array[rear] << endl;
    }
};

int main()
{
    Deque deque(5);
    deque.insertFront(1);
    deque.insertRear(2);
    deque.insertFront(3);
    deque.insertRear(4);
    deque.traverse();
    deque.deleteFront();
    deque.deleteRear();
    deque.traverse();
    return 0;
}
