// SINGLY LINKED LIST ALL OPERATIONS...

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int size = 0;

void printlist(struct Node *head)
{
    if (size == 0)
        printf("\nList is empty..\n");
    else
    {
        printf("\nElements in the list are ");
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

struct Node *insertBeginning(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int value;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &value);
    if (size == 0)
    {
        ptr->data = value;
        ptr->next = NULL;
    }
    else
    {
        ptr->data = value;
        ptr->next = head;
    }
    printf("%d inserted at the beginning in the list..\n", ptr->data);
    size++;
    return ptr;
}

void insertMiddle(struct Node *head)
{
    if (size == 0)
        printf("List is empty..\n");
    else if (size == 1)
        printf("List contains only 1 element..\n");
    else
    {
        int pos;
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        struct Node *temp = head;
        printf("\nEnter the data to be inserted: ");
        scanf("%d", &(ptr->data));
        printf("Enter the position of %d in the list: ", ptr->data);
        scanf("%d", &pos);
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("%d inserted into the list at position %d..\n", ptr->data, pos);
    }
    size++;
}

struct Node *insertEnd(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int value;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &value);
    if (size == 0)
    {
        ptr->data = value;
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        ptr->data = value;
        ptr->next = NULL;
        temp->next = ptr;
    }
    printf("%d inserted at the end in the list..\n", value);
    size++;
    return head;
}

void search(struct Node *head)
{
    if (size == 0)
        printf("List is empty..\n");
    else
    {
        int key, flag = 0, count = 0;
        struct Node *temp = head;
        printf("\nEnter the element to be searched: ");
        scanf("%d", &key);
        do
        {
            if (temp->data == key)
            {
                flag = 1;
                count++;
                break;
            }
            else
            {
                flag = 0;
                count++;
            }
            temp = temp->next;
        } while (temp != NULL);
        if (flag == 1)
            printf("Search successful...\nElement found at position %d in the list...\n", count);
        else
            printf("Search unsuccessful...\nElement not found...\n");
    }
}

struct Node *deleteBeginning(struct Node *head)
{
    if (size == 0)
        printf("List is empty..\n");
    else
    {
        struct Node *temp = head;
        printf("First element %d deleted from the list..\n", head->data);
        size--;
        head = head->next;
        free(temp);
    }
    return head;
}

void deleteMiddle(struct Node *head)
{
    if (size == 0)
        printf("List is empty..\n");
    else if (size == 1)
        printf("List contains only 1 element..\n");
    else
    {
        struct Node *temp = head;
        struct Node *temp2 = head->next;
        int pos;
        printf("\nEnter the position of the element to be deleted: ");
        scanf("%d", &pos);
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        printf("Element %d at position %d deleted from the list..\n", temp2->data, pos);
        size--;
        temp->next = temp2->next;
        free(temp2);
    }
}

void deleteEnd(struct Node *head)
{
    if (size == 0)
        printf("List is empty..\n");
    else if (size == 1)
    {
        printf("Last element %d deleted from the list..\n", head->data);
        free(head);
        size--;
    }
    else
    {
        struct Node *temp = head;
        struct Node *temp2 = head->next;
        while (temp2->next != NULL)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        printf("Last element %d deleted from the list..\n", temp2->data);
        temp->next = NULL;
        free(temp2);
        size--;
    }
}

void main()
{
    struct Node *head;

    int choice;
    printf("\nEnter operation:");
    printf("\n1. Print list");
    printf("\n2. Insertion at the beginning");
    printf("\n3. Insertion in the middle");
    printf("\n4. Insertion at the end");
    printf("\n5. Searching");
    printf("\n6. Deletion at the beginning");
    printf("\n7. Deletion in the middle");
    printf("\n8. Deletion at the end");
    printf("\n9. Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printlist(head);
            break;
        case 2:
            head = insertBeginning(head);
            break;
        case 3:
            insertMiddle(head);
            break;
        case 4:
            head = insertEnd(head);
            break;
        case 5:
            search(head);
            break;
        case 6:
            head = deleteBeginning(head);
            break;
        case 7:
            deleteMiddle(head);
            break;
        case 8:
            deleteEnd(head);
            break;
        case 9:
            printf("\nThank you..\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice...\n");
        }
    } while (1);
}