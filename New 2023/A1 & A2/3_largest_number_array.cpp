#include <iostream>
using namespace std;

int findMax_1(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int findMax_2(int *arr, int size)
{
    if (size == 1)
        return arr[0];
    else
    {
        int max = findMax_2(arr + 1, size - 1);
        return arr[0] > max ? arr[0] : max;
    }
}

int main()
{
    int arr[] = {100, 20, 30, 40, 55};
    cout << "Maximum number: " << findMax_1(arr, 5) << endl;
    cout << "Maximum number: " << findMax_2(arr, 5) << endl;
    return 0;
}