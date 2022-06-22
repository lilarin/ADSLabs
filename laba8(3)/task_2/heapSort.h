//
// Created by User on 12.06.2022.
//

#ifndef TASK_2_HEAPSORT_H
#define TASK_2_HEAPSORT_H

using namespace std;



int getLeftChild(int index) {
    return (2 * index + 1);
}

int getRightChild(int index) {
    return (2 * index + 2);
}

bool isLeaf(int index, int size) {
    return getLeftChild(index) >= size;
}

int getMaxChildIndex(int index, int* arr) {
    if(arr[getLeftChild(index)] < arr[getRightChild(index)]) {
        return getRightChild(index);
    }
    return getLeftChild(index);
}

void siftDownHeap(int* arr, int size, int index) {
    if (isLeaf(index,size)) {
        return;
    }

    int maxChildIndex;
    if (getLeftChild(index) + 1 < size) {
        maxChildIndex = getMaxChildIndex(index,arr);
    }
    else {
        maxChildIndex = getLeftChild(index);
    }

    if (maxChildIndex < index) {
        return;
    }
    swap(arr[maxChildIndex], arr[index]);
    siftDownHeap(arr,size,maxChildIndex);
}

void heapSort(int* arr,int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        siftDownHeap(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        siftDownHeap(arr, i, 0);
    }
}


#endif //TASK_2_HEAPSORT_H
