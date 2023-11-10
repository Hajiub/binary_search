#include <stdio.h>

int recBinSearch(int arr[], int target, int low, int high)
{
    if (low  <= high)
    {
        int mid = (low + high) / 2;
        if (target  > arr[mid])
        {
            return recBinSearch(arr, target, low + 1, high);
        }
        else if (target < arr[mid])
        {
            return recBinSearch(arr, target, low, high - 1);
        }
        else
        {
            return mid;
        }
    }
    else
    {
        return -1;
    }
}
int binSearch(int arr[], int target, size_t size)
{
    int low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (target == arr[mid])
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int target = 4;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = recBinSearch(arr, target, 0, size - 1);

    if (result != -1)
    {
        printf("Target %d found at index %d\n", target, result);
    }
    else
    {
        printf("Target not found\n");
    }

    return 0;
}

