#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
        {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
        {
            smallest = rightChild;
        }

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void enqueue(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int dequeue()
    {
        if (is_empty())
        {
            cerr << "Priority Queue is empty.\n";
            return -1;
        }

        int front = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return front;
    }

    bool is_empty()
    {
        return heap.empty();
    }
};

int main()
{
    PriorityQueue pq;

    pq.enqueue(5);
    pq.enqueue(2);
    pq.enqueue(8);
    pq.enqueue(1);
    pq.enqueue(6);

    while (!pq.is_empty())
    {
        int front = pq.dequeue();
        cout << "Dequeued: " << front << endl;
    }

    return 0;
}
