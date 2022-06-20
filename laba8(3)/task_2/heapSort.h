//
// Created by User on 12.06.2022.
//

#ifndef TASK_2_HEAPSORT_H
#define TASK_2_HEAPSORT_H

using namespace std;


static int getLeftChild(int index) {
    return (2 * index + 1);
}

static int getRightChild(int index) {
    return (2 * index + 2);
}

void siftDownHeap(int *arr, int size, int index)
{
    int largest = index, leftChild = getLeftChild(index),rightChild = getRightChild(index);

    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(arr[index], arr[largest]);

        siftDownHeap(arr, size, largest);
    }
}

void myHeapSort(int* arr,int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        siftDownHeap(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        siftDownHeap(arr, i, 0);
    }
}


#endif //TASK_2_HEAPSORT_H
