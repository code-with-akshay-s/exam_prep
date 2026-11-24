
#include <stdio.h>

#define MAX 100

int main()
{
    int n, i, j, temp1, temp2;

    printf("Enter the number of customers: ");

    if(scanf("%d", &n) != 1 || n <= 0 || n > MAX)
    {
        printf("Invalid number of customers\n");
        return 1;
    }

    int id[MAX], priority[MAX];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter customer ID: ");

        if(scanf("%d", &id[i]) != 1)
        {
            printf("Invalid customer ID\n");
            return 1;
        }

        printf("Enter category priority:\n");
        printf("1. Differently abled\n");
        printf("2. Senior citizen\n");
        printf("3. Defence personnel\n");
        printf("4. Ordinary person\n");

        if(scanf("%d", &priority[i]) != 1 ||
           priority[i] < 1 || priority[i] > 4)
        {
            printf("Invalid priority. Enter a value between 1 and 4.\n");
            return 1;
        }
    }

    // Sort customers according to priority using Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(priority[j] > priority[j + 1])
            {
                // Swap priorities
                temp1 = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp1;

                // Swap corresponding customer IDs
                temp2 = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp2;
            }
        }
    }

    printf("\nCustomer Completion Sequence:\n");

    for(i = 0; i < n; i++)
    {
        printf("ID: %d | Priority: %d | Category: ",
               id[i], priority[i]);

        switch(priority[i])
        {
            case 1:
                printf("Differently abled\n");
                break;

            case 2:
                printf("Senior citizen\n");
                break;

            case 3:
                printf("Defence personnel\n");
                break;

            case 4:
                printf("Ordinary person\n");
                break;
        }
    }

    return 0;
}