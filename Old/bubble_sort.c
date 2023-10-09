#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of elements you want to input: ");
    scanf("%d", &n);
    int a[n];

    // Input elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Sorting the array
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    printf("\nSorted Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}