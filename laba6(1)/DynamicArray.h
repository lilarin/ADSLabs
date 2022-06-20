//
// Created by User on 20.06.2022.
//
using namespace std;

#ifndef MAIN_CPP_DYNAMICARRAY_H
#define MAIN_CPP_DYNAMICARRAY_H

struct matanClassArr {
    char surnameOfLecturer;
    int positionInOrder;
    int amountOfStudents;
};

struct DynamicArray {
    int max_size = 1000,current_size = 0;
    matanClassArr* arr = new matanClassArr[max_size];
    matanClassArr* tempArr;
    matanClassArr error;

    void reallocateMemory() {
        tempArr = new matanClassArr[max_size];

        for (int i = 0; i < current_size; i++) {
            tempArr[i] = arr[i];
        }
        delete [] arr;
        max_size = max_size * 2;
        arr = new matanClassArr[max_size];
        for (int i = 0; i < max_size / 2; i++) {
            arr[i] = tempArr[i];
        }
        delete [] tempArr;
    }

    bool checkIsFull() const {
        if (current_size >= max_size) {
            return true;
        }
        return false;
    }

    bool checkIsEmpty() const {
        if (current_size == 0) {
            return true;
        }
        return false;
    }

    void push_back(matanClassArr *data) {
        if (checkIsFull()) {
            reallocateMemory();
        }
        arr[current_size] = *data;
        current_size++;
    }

    void push_front(matanClassArr *data) {
        if (checkIsFull()) {
            reallocateMemory();
        }
        for (int i = current_size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = *data;
        current_size++;
    }

    matanClassArr pop_back() {
        if (checkIsEmpty()) {
            return error;
        }
        current_size--;
        matanClassArr temp = arr[current_size];
        return temp;
    }

    matanClassArr pop_front() {
        if (checkIsEmpty()) {
            return error;
        }
        matanClassArr temp = arr[0];
        for (int i = 0; i < current_size-1; i++) {
            arr[i] = arr[i+1];
            if (i == current_size-1) {
                arr[current_size] = temp;
            }
        }
        current_size--;
        return temp;
    }

    matanClassArr get(int number) const {
        matanClassArr temp = arr[number];
        return temp;
    }

    void insert(matanClassArr *data,int position) {
        if (checkIsFull()) {
            reallocateMemory();
        }
        for (int i = current_size; i > position; i--) {
            arr[i] = arr[i-1];
        }
        arr[position] = *data;
        current_size++;
    }

    void remove(int position) {
        for (int i = position; i < current_size; i++) {
            arr[i] = arr[i+1];
        }
        current_size--;
    }

    int sizeOfArray() const {
        return current_size;
    }

    int capacity() const {
        return max_size;
    }

    void print() const {
        matanClassArr temp;
        for (int i = 0; i < current_size; i++) {
            temp = get(i);
            cout << temp.surnameOfLecturer << " " << temp.positionInOrder << " " << temp.amountOfStudents << endl;
        }
    }

    void clear() {
        current_size = 0;
        delete [] arr;
    }
    ~DynamicArray() {
        delete[] arr;
    }
};


#endif //MAIN_CPP_DYNAMICARRAY_H
