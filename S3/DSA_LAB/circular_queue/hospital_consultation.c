
#include <stdio.h>
#define MAX 100

struct patient
{
    int patient_id;
    char patient_name[50];
};

struct patient queue[MAX];
int front = -1, rear = -1, N;

void add()
{
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
        rear = (rear + 1) % N;

    printf("Enter the patient ID: ");
    if(scanf("%d", &queue[rear].patient_id) != 1)
    {
        printf("Invalid patient ID\n");
        return;
    }

    printf("Enter the patient name: ");
    if(scanf("%49s", queue[rear].patient_name) != 1)
    {
        printf("Invalid patient name\n");
        return;
    }

    printf("Patient added successfully\n");
}

void delete()
{
    if(front == -1)
    {
        printf("Underflow\n");
        return;
    }

    printf("Deleted patient record:\n");
    printf("Patient ID: %d", queue[front].patient_id);
    printf("\nPatient name: %s\n", queue[front].patient_name);

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % N;
}

void display()
{
    if(front == -1)
    {
        printf("No patients in list\n");
        return;
    }

    int i = front;

    printf("Patients waiting:\n");

    while(1)
    {
        printf("Patient ID: %d", queue[i].patient_id);
        printf("\nPatient name: %s\n", queue[i].patient_name);

        if(i == rear)
            break;

        i = (i + 1) % N;
    }
}

int main()
{
    int choice;

    printf("Enter the size of the queue: ");

    if(scanf("%d", &N) != 1 || N < 1 || N > MAX)
    {
        printf("Invalid size\n");
        return 1;
    }

    while(1)
    {
        printf("\n---- HOSPITAL PATIENT CONSULTATION MANAGEMENT SYSTEM ----\n");
        printf("1. Add patients\n");
        printf("2. Call patient\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }

        switch(choice)
        {
            case 1:
                add();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting application\n");
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}