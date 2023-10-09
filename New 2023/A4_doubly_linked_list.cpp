#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

bool isEmpty()
{
    return head == NULL;
}

void insertStart(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    if (isEmpty())
    {
        ptr->next = NULL;
    }
    else
    {
        head->prev = ptr;
        ptr->next = head;
    }
    head = ptr;
}

void insertMiddle(int data, int pos)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;
    temp->next->prev = ptr;
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->prev = temp;
}

void insertEnd(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (isEmpty())
    {
        head = ptr;
        ptr->prev = NULL;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void deleteStart()
{
    struct Node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
}

void deleteEnd()
{
    struct Node *ptr = head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    free(ptr->next);
    ptr->next = NULL;
}

void deleteMiddle(int pos)
{   
    struct Node *ptr = head;
    for (int i=0; i<pos -1; i++)
        ptr = ptr->next;
    ptr->next = ptr->next->next;
    free(ptr->next->prev);
    ptr->next->prev = ptr;
}

void traverse()
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int search(int data)
{
    int pos = -1;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        pos++;
        if (data == ptr->data)
            return pos;
        ptr = ptr->next;
    }
    return -1;
}

int main()
{
    insertStart(10);
    insertStart(20);
    insertStart(30);
    insertEnd(40);
    insertMiddle(50, 1);
    traverse();
    insertMiddle(60, 3);
    traverse();
    deleteStart();
    traverse();
    deleteEnd();
    traverse();
    deleteMiddle(2);
    traverse();
    cout << search(550) << endl;

    return 0;
}