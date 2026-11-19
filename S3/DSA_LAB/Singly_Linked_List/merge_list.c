
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create()
{
    int n;
    struct node *head = NULL;
    struct node *tail = NULL;

    printf("Enter the number of nodes: ");

    if(scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid number of nodes\n");
        return NULL;
    }

    printf("Enter the sorted linked list:\n");

    for(int i = 0; i < n; i++)
    {
        struct node *newNode;

        newNode = (struct node*)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return head;
        }

        printf("Enter value: ");

        if(scanf("%d", &newNode->data) != 1)
        {
            printf("Invalid input\n");
            free(newNode);
            return head;
        }

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

struct node* merge(struct node *head1, struct node *head2)
{
    struct node dummy;
    struct node *tail = &dummy;

    dummy.next = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    if(head1 != NULL)
        tail->next = head1;

    if(head2 != NULL)
        tail->next = head2;

    return dummy.next;
}

void display(struct node *head)
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("No nodes\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void freeList(struct node *head)
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
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    printf("Enter first sorted list:\n");
    head1 = create();

    printf("\nEnter second sorted list:\n");
    head2 = create();

    head3 = merge(head1, head2);

    printf("\nThe final merged list:\n");
    display(head3);

    freeList(head3);

    return 0;
}