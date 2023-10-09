// Question -> Perform operations on arrays
// Name -> Sharaneshwar Bharat Punjal
// Roll No. -> 82
// Branch -> CM3I

#include <stdio.h>
#include <stdlib.h>

void traversal(int a[], int n)
{
    printf("\nArray elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int insert(int a[], int n)
{
    int key, pos;
    printf("\nEnter the element to be inserted into the array: ");
    scanf("%d", &key);
    printf("Enter the position of %d in the array: ", key);
    scanf("%d", &pos);
    printf("Element %d inserted successfully into the array at position %d\n", key, pos);
    pos--;
    n++;
    for (int i = n - 1; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = key;
    return n;
}

int search(int a[], int n, int key)
{
    // Using linear search as binary search works only on sorted arrays...
    int pos = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == key)
        {
            pos = i;
            break;
        }
    return pos;
}

int delete (int a[], int n)
{
    int key;
    printf("\nEnter an element to delete from the array: ");
    scanf("%d", &key);
    int pos = search(a, n, key);
    if (pos == -1)
        printf("\nElement not found in the array...\n");
    else
    {
        printf("Element %d deleted successfully from the array from position %d\n", key, pos+1);
        for (int i = pos; i < n; i++)
        {
            a[i] = a[i + 1];
        }
    }
    n--;
    return n;
}

void sort(int a[], int n)
{
    // Performing Bubble Sort...
    printf("\n--SORTING FORMAT--");
    printf("\n1 -> Ascending order");
    printf("\n2 -> Descending order");
    printf("\nEnter your choice -> ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1; j++)
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1; j++)
                if (a[j] < a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
        break;
    default:
        printf("\nInvalid choice...\n");
    }
    printf("\nSorted Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void main()
{
    int n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    // Input elements of the array...
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Array Operations...
    printf("\n--Array Operations--");
    printf("\n1 -> Insertion");
    printf("\n2 -> Deletion");
    printf("\n3 -> Traversal");
    printf("\n4 -> Searching");
    printf("\n5 -> Sorting");
    printf("\n6 -> Exit\n");
    do
    {
        printf("\nEnter your choice -> ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            n = insert(arr, n);
            break;
        case 2:
            n = delete (arr, n);
            break;
        case 3:
            traversal(arr, n);
            break;
        case 4:
            printf("\nEnter element to be searched: ");
            scanf("%d", &key);
            int pos = search(arr, n, key);
            if (pos != -1)
                printf("\nSearch successful...\nElement found at position %d...\n", pos);
            else
                printf("\nSearch unsuccessful...\nElement not found...\n"); break;
        case 5:
            sort(arr, n);
            break;
        case 6:
            printf("\nThank you..\n\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice..\nEnter again..\n");
        }
    } while (1);
}