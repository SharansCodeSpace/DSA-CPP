#include <stdio.h>
void main()
{
    int *ptr;
    int a[] = {1,2,3};
    int p,q,r;
    ptr = &a[0];
    printf("a[0] = *ptr = %d",*ptr);
    printf("\na[1] = *(++ptr) = %d",*(++ptr));
    printf("\na[2] = *(++ptr) = %d",*(++ptr));
    ptr = &a[0];
    printf("\n&a[0] = ptr = %x",ptr);
    printf("\n&a[1] = ++ptr = %x",++ptr);
    printf("\n&a[2] = ++ptr = %x",++ptr);
    printf("\nAddress of ptr = &ptr = %x",&ptr);
}