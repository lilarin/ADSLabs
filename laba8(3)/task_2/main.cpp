#include <iostream>
#include "heapSort.h"
#include "insertionSort.h"
#include <ctime>

using namespace std;

void randomPermutation(int *arr, int size) {
    for(int j,i=size-1;i>=0;i--) {
        j = rand() % size;
        swap(arr[i],arr[j]);
    }
}

int main()
{
    cout << "Additional task." << endl;
    srand(time(nullptr));
    int size = 50000;
    int *arr = new int[size];
    for (int i = 0; i <size; i++) {
        arr[i]=i+1;
    }

    randomPermutation(arr,size);

    clock_t HeapTimeStart = clock();
    heapSort(arr, size);
    clock_t  HeapTimeEnd = clock();
    float HeapTime = (float(HeapTimeEnd - HeapTimeStart)) / CLOCKS_PER_SEC;
    cout << "Sorting time using heap sort: " << HeapTime << endl;

    randomPermutation(arr,size);

    clock_t StlTimeStart = clock();
    insertionSort(arr, size);
    clock_t StlTimeEnd = clock();
    float StlTime = (float(StlTimeEnd - StlTimeStart)) / CLOCKS_PER_SEC;
    cout << "Sorting time using insertion sort: " << StlTime << endl;

}
