// Circular queue using arrays
// By Sharaneshwar Bharat Punjal, CM3I

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q)
{
    int val;
    printf("\nEnter value of be enqueued: ");
    scanf("%d", &val);
    if (isFull(q))
    {
        printf("\nQueue is full...\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("\n%d enqueued into the queue at the position %d\n", val, q->r);
    }
}

void dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty...\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        printf("\n%d dequeued from the queue from the position %d\n", q->arr[q->f], q->f);
    }
}

void printqueue(struct queue *q)
{

    if (isEmpty(q))
    {
        printf("\nQueue is Empty...\n");
    }
    else
    {
        int a = q->f + 1;
        printf("\nQueue elements from front to rear:\n");
        while (a <= q->r)
        {
            printf("%d\n", q->arr[a]);
            a++;
        }
    }
}

void main()
{
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int choice;
    printf("\nCIRCULAR QUEUE OPERATIONS: ");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Print queue");
    printf("\n4. Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            printqueue(&q);
            break;
        case 4:
            printf("\nThank you...\n");
            exit(0);
        default:
            printf("\nInvalid choice...\nEnter again...\n");
        }
    } while (1);
}