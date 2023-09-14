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
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
            if (a[smallest] > a[j])
                smallest = j;
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
    }

    printf("\nSorted Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
