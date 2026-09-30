// Binary Search — Iterative :-

#include <stdio.h>

int main()
{
    int a[100], n, key;
    int low, high, mid;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            printf("Element found at index %d", mid);
            found = 1;
            break;
        }
        else if (key > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found == 0)
    {
        printf("Element not found");
    }

    return 0;
}

// => Binary Search Program (recursion):-

#include <stdio.h>

int binarySearch(int a[], int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (a[mid] == key)
    {
        return mid;
    }

    if (key > a[mid])
    {
        return binarySearch(a, mid + 1, high, key);
    }
    else
    {
        return binarySearch(a, low, mid - 1, key);
    }
}

int main()
{

    int size, key, result;

    printf("enter the array size : ");
    scanf("%d", &size);

    int a[size];

    for (int i = 0; i < size; i++)
    {
        printf("enter the array element : ");
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(a, 0, size - 1, key);

    if (result == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index %d", result);
    }
    return 0;
}