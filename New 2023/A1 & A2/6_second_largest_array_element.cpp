#include <iostream>
using namespace std;

int main()
{
    int arr[] = {34, 23, 123, 543, 22};
    int largest = arr[0], second_largest = arr[0];
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
            second_largest = arr[i];
    }
    cout << "Second largest element: " << second_largest << endl;
    return 0;
}