#!/usr/bin/env python3
import sys

def rec_binary_search(arr: list, target: int, low: int, high: int):
    if low <= high:
        mid = (low + high) // 2

        if target > arr[mid]:
            return rec_binary_search(arr, target, mid + 1, high)
        elif target < arr[mid]:
            return rec_binary_search(arr, target, low, mid - 1)
        else:
            return mid
    else:
        return -1

def binary_search(arr: list, target: int) -> int:
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        # search in the right side
        if target > arr[mid]:
            low = mid + 1

        # search in the left side
        elif target < arr[mid]:
            high = mid - 1

        else:
            return mid

    return -1

def main():
    arr = [1, 2, 3, 4, 5, 6, 7]
    target = 7
    result = rec_binary_search(arr, target, 0, len(arr) - 1)

    if result != -1:
        print(f'Target {target} found at index {result}')
        sys.exit(0)
    else:
        print('Not found')
        sys.exit(1)

if __name__ == '__main__':
    main()
