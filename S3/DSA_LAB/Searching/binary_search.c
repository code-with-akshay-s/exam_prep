
#include <stdio.h>

int binarySearch(int arr[], int key, int n)
{
    int high = n - 1, low = 0, mid;

    while(low <= high)
    {
        mid = low + (high - low) / 2;

        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid array size\n");
        return 0;
    }

    int arr[n];

    printf("Enter the elements in ascending order:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, key, n);

    if(result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}
