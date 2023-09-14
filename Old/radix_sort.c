// Radix sort by Sharaneshwar Punjal
#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of elements you want to input: ");
    scanf("%d", &n);
    int a[n], digit[n];

    // Input elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Counting number of passes
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    int count = 0;
    do
    {
        max /= 10;
        ++count;
    } while (max != 0);

    // Sorting the array using radix sort
    int temp, d = 10, j;
    for (int k = 1; k <= count; k++)
    {
        for (int i = 1; i < n; i++)
        {
            temp = a[i];
            j = i - 1;
            while ((temp % d) / (d / 10) < (a[j] % d) / (d / 10))
            {
                a[j + 1] = a[j];
                j--;
                if (j < 0)
                    break;
            }
            a[j + 1] = temp;
        }
        d *= 10;
    }

    // Display sorted elements
    printf("\nSorted Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
