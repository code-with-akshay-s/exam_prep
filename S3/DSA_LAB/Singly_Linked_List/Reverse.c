
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createNode()
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the data: ");

    if(scanf("%d", &newNode->data) != 1)
    {
        printf("Invalid input\n");
        free(newNode);
        return;
    }

    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

void reverseList(struct node **current)
{
    struct node *next;
    struct node *prev = NULL;

    if(*current == NULL)
    {
        printf("No nodes to reverse\n");
        return;
    }

    while(*current != NULL)
    {
        next = (*current)->next;
        (*current)->next = prev;
        prev = *current;
        *current = next;
    }

    head = prev;
}

void display()
{
    if(head == NULL)
    {
        printf("No nodes\n");
        return;
    }

    struct node *temp = head;

    printf("Reversed linked list: ");

    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void freeList()
{
    struct node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n;

    printf("Enter the number of nodes: ");

    if(scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid number of nodes\n");
        return 1;
    }

    for(int i = 0; i < n; i++)
    {
        createNode();
    }

    reverseList(&head);
    display();

    freeList();

    return 0;
}