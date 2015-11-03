/*
Jerry Vogel
10/16/15
Heaps.  Implementing and sorting
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cmath>

using namespace std;

int arrLength = 100;

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void sink(int array [], int start, int end)
{
    int root = start;
    while (root * 2 + 1 <= end)
    {
        int child = root * 2 + 1;
        int swapper = root;
        if(array[swapper] < array[child])
        {
            swapper = child;
        }
        if(child + 1 <= end && array[swapper] < array[child + 1])
        {
            swapper = child + 1;
        }
        if(swapper == root)
        {
            return;
        }
        else
        {
            swap(array[root], array[swapper]);
            root = swapper;
        }
    }
}

void heapify(int array [], int count)
{
    int start = floor((count - 2) / 2);
    while (start >= 0)
    {
        sink(array, start, count - 1);
        start--;
    }
}

void heapsort(int array [], int count)
{
    heapify(array, count);
    int end = count - 1;
    while (end > 0)
    {
        swap(&array[end], &array[0]);
        end--;
        sink(array, 0, end);
    }
}

int main()
{    
    srand(time(NULL));
    int arr [arrLength];
    for(int i = 0; i < arrLength; i++)
    {
        arr[i] = (rand() % (arrLength * 3));
        cout << arr[i] << endl;
    }
    cout << "Array Made" << endl << endl;
    heapsort(arr, arrLength);
    cout << "Sorted list:" << endl;
    for(int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}