
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1, N;

void enqueue()
{
    int item;

    printf("Enter the value you want to enqueue: ");
    if(scanf("%d", &item) != 1)
    {
        printf("Invalid input\n");
        return;
    }

    if((rear + 1) % N == front)
    {
        printf("Overflow\n");
        return;
    }
    else if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % N;
    }

    queue[rear] = item;
    printf("%d added successfully\n", item);
}

void dequeue()
{
    if(front == -1)
    {
        printf("Underflow\n");
        return;
    }

    int val = queue[front];

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % N;
    }

    printf("%d deleted successfully\n", val);
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;

    while(1)
    {
        printf("%d\t", queue[i]);

        if(i == rear)
        {
            break;
        }

        i = (i + 1) % N;
    }

    printf("\n");
}

int main()
{
    int choice;

    printf("Enter the size of the queue: ");

    if(scanf("%d", &N) != 1 || N <= 0 || N > MAX)
    {
        printf("Invalid size\n");
        return 1;
    }

    while(1)
    {
        printf("\n----MENU----\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}