
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void createNode()
{
    struct node *newNode = NULL;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display()
{
    if(head == NULL)
    {
        printf("No nodes\n");
        return;
    }

    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void reverse()
{
    if(head == NULL)
    {
        return;
    }

    struct node *temp = NULL;
    struct node *current = head;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if(temp != NULL)
    {
        head = temp->prev;
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

    printf("\nOriginal List:\n");
    display();

    reverse();

    printf("\nReversed List:\n");
    display();

    struct node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}