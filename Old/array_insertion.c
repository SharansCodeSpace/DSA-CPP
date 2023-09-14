#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n;
    printf("Enter number of elements you want to input: ");
    scanf("%d",&n);
    int a[n];

    // Input elements
    printf("Enter %d elements:\n",n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    // Display elements
    printf("\nEntered array elements: ");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);

    // Insertion method
    int key,pos;
    printf("\n\nEnter an element to insert into the array: ");
    scanf("%d",&key);
    printf("Enter the position of %d in the array: ",key);
    scanf("%d",&pos);
    pos--;
    n++;
    for(int i=n-1; i>pos; i--)
        a[i] = a[i-1];
    a[pos] = key;

    // Display elements
    printf("\nUpdated array after insertion: ");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
}