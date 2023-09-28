#include <iostream>
using namespace std;

int main()
{
    int arr[] = {100, 20, 30, 40, 55};
    int max = arr[0];
    for (int i = 0; i < 5; i++)
        if (arr[i] > max)
            max = arr[i];
    cout << "Maximum number: " << max << endl;
    return 0;
}