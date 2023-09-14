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
    int key, pos=-1;
    printf("\n\nEnter an element to delete from the array: ");
    scanf("%d",&key);
    for(int i=0; i<n; i++)
    {
        if(a[i]==key)
        {
            pos = i;
            break;
        }
    }
    if (pos==-1)
        printf("Element not found in the array...");
    else
    {
        for(int i=pos; i<n; i++)
        {
            a[i] = a[i+1];     
        }
    }
    n--;
    // Display elements
    printf("\nUpdated array after deletion: ");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
}