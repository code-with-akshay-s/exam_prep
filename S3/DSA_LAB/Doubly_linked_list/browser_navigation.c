
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[50];
    struct node *next;
    struct node *prev;
};

struct node* visitPage(struct node *current, char page[50])
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return current;
    }

    strcpy(newNode->data, page);
    newNode->next = NULL;
    newNode->prev = current;

    if(current != NULL)
    {
        struct node *temp = current->next;

        while(temp != NULL)
        {
            struct node *deleteNode = temp;
            temp = temp->next;
            free(deleteNode);
        }

        current->next = newNode;
    }

    current = newNode;

    printf("Currently at %s\n", current->data);
    return current;
}

struct node* nextPage(struct node *current)
{
    if(current == NULL)
    {
        printf("No page\n");
    }
    else if(current->next == NULL)
    {
        printf("No next page\n");
    }
    else
    {
        current = current->next;
        printf("Currently at %s\n", current->data);
    }

    return current;
}

struct node* previousPage(struct node *current)
{
    if(current == NULL)
    {
        printf("No page\n");
    }
    else if(current->prev == NULL)
    {
        printf("No previous page\n");
    }
    else
    {
        current = current->prev;
        printf("Currently at %s\n", current->data);
    }

    return current;
}

int main()
{
    int choice;
    char page[50];
    struct node *current = NULL;

    while(1)
    {
        printf("\n----MENU----\n");
        printf("1. Visit Page\n2. Next Page\n3. Previous Page\n4. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            break;
        }

        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter the page name: ");
                fgets(page, sizeof(page), stdin);
                page[strcspn(page, "\n")] = '\0';

                current = visitPage(current, page);
                break;

            case 2:
                current = nextPage(current);
                break;

            case 3:
                current = previousPage(current);
                break;

            case 4:
                printf("Exiting browser navigation\n");

                while(current != NULL && current->prev != NULL)
                {
                    current = current->prev;
                }

                while(current != NULL)
                {
                    struct node *temp = current;
                    current = current->next;
                    free(temp);
                }

                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    while(current != NULL && current->prev != NULL)
    {
        current = current->prev;
    }

    while(current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}