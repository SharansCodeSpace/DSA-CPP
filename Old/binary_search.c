#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of elements you want to input: ");
    scanf("%d", &n);
    int a[n];

    // Input elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to be searched: ");
    int key;
    scanf("%d", &key);

    // Sorting the array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    // Binary search
    int pos = -1;
    int first = 0, last = n - 1;
    int middle;
    while (first <= last)
    {
        middle = (first + last) / 2;
        if (key < a[middle])
            last = middle - 1;
        else if (key > a[middle])
            first = middle + 1;
        else if (key == a[middle])
        {
            pos = middle;
            break;
        }
    }

    printf("\nSorted array:\n");
    for (int j = 0; j < n; j++)
        printf("%d ",a[j]);
    
    if(pos==-1)
        printf("\nElement not found in the array...");
    else
        printf("\nElement found in the array at position %d...", pos+1);
}