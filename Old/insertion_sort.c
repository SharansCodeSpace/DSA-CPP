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
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
            if (j < 0)
                break;
        }
        a[j + 1] = temp;
    }

    printf("\nSorted Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
