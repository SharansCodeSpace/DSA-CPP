#include <stdio.h>
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

    printf("Enter element to be searched: ");
    int key;
    scanf("%d",&key);

    // Linear search starts
    int pos=-1;
    for(int i=0; i<n; i++)
        if(a[i]==key)
        {
            pos = i;
            break;
        }
    if(pos==-1)
        printf("\nSearch unsuccessful...\nElement not found in the array...");
    else
        printf("\nSearch successful...\nElement found in the array at position %d...",pos+1);
}