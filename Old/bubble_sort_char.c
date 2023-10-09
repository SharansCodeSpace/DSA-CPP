#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of elements you want to input: ");
    scanf("%d", &n);
    char a[n + 1];

    // Input elements
    printf("Enter %d elements: ", n);
    scanf("%s", &a);

    printf("\nArray Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%c ", a[i]);

    printf("\nArray Elements in integer form are: ");
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

    //Display
    printf("\n\nSorted Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%c ", a[i]);
    
    printf("\nSorted Array Elements in integer form are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
