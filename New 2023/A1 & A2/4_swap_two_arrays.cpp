// Write a program that uses interchange function to swap the contents of the two arrays using pointers.

#include <iostream>
using namespace std;

int n = 5;

void swap(int *a1, int *a2)
{
    for (int i = 0; i < n; i++)
    {
        int temp = *(a1 + i);
        *(a1 + i) = *(a2 + i);
        *(a2 + i) = temp;
    }
}

void print(int *arr) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main()
{
    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {6, 7, 8, 9, 10};
    cout << "Before Swapping: " << endl;
    cout << "Array 1: ";
    print(a1);
    cout << "Array 2: ";
    print(a2);
    swap(a1, a2);
    cout << "After Swapping: " << endl;
    cout << "Array 1: ";
    print(a1);
    cout << "Array 2: ";
    print(a2);
    return 0;
}