#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void bubbleArray(int size, int* arr) {
    bool isSorted = true;
    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < size-i; j++)
        {
            if(arr[j] > arr[j+1]) {
                isSorted=false;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (isSorted) {
            return;
        }
    }
}

int linearSearch(int element,int* arr, int size) {
    for (int i=0; i<size; i++)
    {
        if (element==arr[i]) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int element,int* arr, int size) {
    int leftBorder = 0, rightBorder = size - 1;
    while (rightBorder - leftBorder > 1) {
        int middleElement = (leftBorder + rightBorder) / 2;

        if (arr[middleElement] < element) {
            leftBorder = middleElement;
        } else if (arr[middleElement] > element) {
            rightBorder = middleElement;
        } else {
            return middleElement;
        }
    }
    return -1;
}

int main() {
    int size=1000,iteration=0,repeats=100000;
    int arr[size];
    int element = rand() % 4000 - 1999;
    srand ( time(NULL) );
    for (int i=0; i<size; i++) {
        arr[i]=rand() % 4000 - 1999;
    }
    bubbleArray(size, arr);
    if (arr[linearSearch(element, arr, size)] == arr[binarySearch(element, arr, size)] || (linearSearch(element, arr, size) == -1 && binarySearch(element, arr, size) == -1)) {
        cout << "Test passed successfully";
    } else {
        cout << "ERROR";
        cout << "\nlinear index is: " << linearSearch(element, arr, size) << "\nbinary index is: " << binarySearch(element, arr, size);
    }

    clock_t startTimeLinear = clock();
    while (iteration < repeats) {
        linearSearch(element, arr, size);
        iteration += 1;
    }
    clock_t endTimeLinear = clock();
    double secondsLinear = (double(endTimeLinear - startTimeLinear)) / CLOCKS_PER_SEC;
    cout << "\nTime of linear is: " << secondsLinear;

    iteration = 0;
    clock_t startTimeBinary = clock();
    while (iteration < repeats) {
        binarySearch(element, arr, size);
        iteration += 1;
    }
    clock_t endTimeBinary = clock();
    double secondsBinary = (double(endTimeBinary - startTimeBinary)) / CLOCKS_PER_SEC;
    cout << "\nTime of binary is: " << secondsBinary;
    return 0;
}