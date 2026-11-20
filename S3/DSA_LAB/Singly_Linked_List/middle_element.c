
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int main()
{
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("The linked list is empty\n");
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        struct node *newNode;
        newNode = (struct node*)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter the value: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct node *slow = head;
    struct node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("The middle element is: %d\n", slow->data);

    struct node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}