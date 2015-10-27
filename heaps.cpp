/*
Jerry Vogel
10/16/15
Heaps.  Implementing and sorting
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int arrLength = 10;

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void sink(int array [], int parent, int sizeOfArray)
{
    int leftChild, rightChild;
    leftChild = 2 * parent + 1;
    if(leftChild >= sizeOfArray || parent < 0)
    {
        return;
    }
    rightChild = leftChild + 1;
    
    if(rightChild < arrLength && array[rightChild] >= array[parent])
    {
        swap(&array[rightChild], &array[parent]);
    }
    
    if(array[leftChild] >= array[parent])
    {
        swap(&array[leftChild], &array[parent]);   
    }
    
    parent--;
    sink(array, parent, sizeOfArray);
}

void heapify(int array [], int sizee)
{
    for(int i = arrLength / 2 ; i >= 1; i--)
    {
        sink(array, i, sizee);
    }
}

void heapsort(int array [])
{
    for(int i = 1; i < arrLength; i++)
    {
        heapify(array, (arrLength - i));
        cout << "Heap" << endl;
        for(int j = 0; j < arrLength; j++)
        {
            cout << array[j] << endl;
        }
        swap(&array[0], &array[arrLength - i]);
        cout << "After Switch" << endl;
        for(int j = 0; j < arrLength; j++)
        {
            cout << array[j] << endl;
        }
    }
    cout << "ran" << endl;
}

int main()
{    
    srand(time(NULL));
    int arr [arrLength];
    for(int i = 0; i < arrLength; i++)
    {
        arr[i] = (rand() % 20);
        cout << arr[i] << endl;
    }
    cout << "Array Made" << endl << endl;
    heapsort(arr);
    cout << "Sorted list:" << endl;
    for(int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}