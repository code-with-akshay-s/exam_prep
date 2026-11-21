
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode, *temp;
    struct node *ptr, *prev;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n < 0)
    {
        printf("Invalid number of nodes\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp = head;

    while(temp != NULL)
    {
        prev = temp;
        ptr = temp->next;

        while(ptr != NULL)
        {
            if(temp->data == ptr->data)
            {
                prev->next = ptr->next;
                free(ptr);
                ptr = prev->next;
            }
            else
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }

        temp = temp->next;
    }

    printf("List after removing duplicates:\n");

    temp = head;

    if(temp == NULL)
        printf("List is empty\n");

    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}