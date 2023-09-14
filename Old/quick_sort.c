#include <stdio.h>
void quickSort(int *a, int first, int last);
void subArray(int *a, int first, int last, int *pivotpos);

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
    quickSort(a, 0, n - 1);

    printf("\nSorted Array Elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void subArray(int *a, int first, int last, int *pivotpos)
{
    int left = first; //initially left point to the first element of the array
    int right = last; //initially right point to the last element of the array
    *pivotpos = left; //initially pivot point to first element of the array
    int temp;         //used for swapping values

    while (1)
    {

        //pivot pointing at left
        while (a[*pivotpos] <= a[right] && *pivotpos != right)
        {
            right--; //move right one position towards left
        }

        //both left and right pointing at same element of the array
        if (*pivotpos == right)
        {
            break;
        }

        //pivot element greater than right element. swap pivot and right element.
        else if (a[*pivotpos] > a[right])
        {
            temp = a[right];
            a[right] = a[*pivotpos];
            a[*pivotpos] = temp;
            *pivotpos = right; //pivot is now pointing to right
        }

        //pivot pointing to right
        while (a[*pivotpos] >= a[left] && *pivotpos != left)
        {
            left++; //move left one position towards right
        }

        //both left and right pointing at the same element of the array
        if (*pivotpos == left)
        {
            break;
        }

        //pivot element smaller than left element. swap pivot and left element.
        else if (a[*pivotpos] < a[left])
        {
            temp = a[left];
            a[left] = a[*pivotpos];
            a[*pivotpos] = temp;
            *pivotpos = left; //pivot is now pointing to left
        }
    }
}

void quickSort(int *a, int first, int last)
{
    int pivotpos;
    if (first < last)
    {
        // finding the pivot location and divide the array
        subArray(a, first, last, &pivotpos);
        quickSort(a, first, pivotpos - 1); //quick sort the left sub array
        quickSort(a, pivotpos + 1, last);  //quick sort the right sub array
    }
}
