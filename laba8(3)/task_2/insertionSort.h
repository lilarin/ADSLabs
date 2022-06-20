//
// Created by User on 20.06.2022.
//

#ifndef MAIN_CPP_INSERTIONSORT_H
#define MAIN_CPP_INSERTIONSORT_H


void insertionSort(int *arr,int size) {
    for(int i=1;i<size;i++) {
        for(int j=i-1;j>=0;j--) {
            if( arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


#endif //MAIN_CPP_INSERTIONSORT_H
