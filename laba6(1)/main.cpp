#include <iostream>
#include <string>
#include <ctime>
#include "LinkedList.h"
#include "DynamicArray.h"

using namespace std;


int main() {
    DynamicArray array;
    LinkedList list;
    srand(time(nullptr));
    int i=0;
    clock_t startTimeVector = clock();
    clock_t startTimeVectorTest1 = clock();
    while (i++ < 50000) {
        matanClassArr data = {'t', 1, 1};
        array.push_back(&data);
    }
    clock_t endTimeVectorTest1 = clock();
    i=0;

    clock_t startTimeVectorTest2 = clock();
    while (i++ < 10000) {
        matanClassArr data = {'t', 1, 1};
        array.push_front(&data);
    }
    clock_t endTimeVectorTest2 = clock();
    i=0;

    clock_t startTimeVectorTest3 = clock();
    while (i++ < 20000) {
        int n = rand() % 59999 + 1;
        array.get(n);
    }
    clock_t endTimeVectorTest3 = clock();
    i=0;

    clock_t startTimeVectorTest4 = clock();
    while (i++ < 5000) {
        array.pop_front();
    }
    clock_t endTimeVectorTest4 = clock();
    i=0;

    clock_t startTimeVectorTest5 = clock();
    while (i++ < 5000) {
        array.pop_back();
    }
    clock_t endTimeVectorTest5 = clock();
    clock_t endTimeVector = clock();
    i=0;

    double secondsVectorTest1 = (double(endTimeVectorTest1 - startTimeVectorTest1)) / CLOCKS_PER_SEC;
    cout << "Time of push_back is: " << secondsVectorTest1;

    double secondsVectorTest2 = (double(endTimeVectorTest2 - startTimeVectorTest2)) / CLOCKS_PER_SEC;
    cout << "\nTime of push_front is: " << secondsVectorTest2;

    double secondsVectorTest3 = (double(endTimeVectorTest3 - startTimeVectorTest3)) / CLOCKS_PER_SEC;
    cout << "\nTime of get is: " << secondsVectorTest3;

    double secondsVectorTest4 = (double(endTimeVectorTest4 - startTimeVectorTest4)) / CLOCKS_PER_SEC;
    cout << "\nTime of pop_front is: " << secondsVectorTest4;

    double secondsVectorTest5 = (double(endTimeVectorTest5 - startTimeVectorTest5)) / CLOCKS_PER_SEC;
    cout << "\nTime of pop_back is: " << secondsVectorTest5;

    double secondsVector = (double(endTimeVector - startTimeVector)) / CLOCKS_PER_SEC;
    cout << "\nArray run time is: " << secondsVector;


    // list
    clock_t startTimeList = clock();
    clock_t startTimeListTest1 = clock();
    while (i++ < 50000) {
        matanClassList data = {'t', 1, 1};
        list.push_back(&data);
    }
    clock_t endTimeListTest1 = clock();
    i=0;

    clock_t startTimeListTest2 = clock();
    while (i++ < 10000) {
        matanClassList data = {'t', 1, 1};
        list.push_front(&data);
    }
    clock_t endTimeListTest2 = clock();
    i=0;

    clock_t startTimeListTest3 = clock();
    while (i++ < 20000) {
        int n = rand() % 59999 + 1;
        list.get(n);
    }
    clock_t endTimeListTest3 = clock();
    i=0;

    clock_t startTimeListTest4 = clock();
    while (i++ < 5000) {
        list.pop_front();
    }
    clock_t endTimeListTest4 = clock();
    i=0;

    clock_t startTimeListTest5 = clock();
    while (i++ < 5000) {
        list.pop_back();
    }
    clock_t endTimeListTest5 = clock();
    clock_t endTimeList = clock();


    double secondsListTest1 = (double(endTimeListTest1 - startTimeListTest1)) / CLOCKS_PER_SEC;
    cout << "\n\nTime of push_back is: " << secondsListTest1;

    double secondsListTest2 = (double(endTimeListTest2 - startTimeListTest2)) / CLOCKS_PER_SEC;
    cout << "\nTime of push_front is: " << secondsListTest2;

    double secondsListTest3 = (double(endTimeListTest3 - startTimeListTest3)) / CLOCKS_PER_SEC;
    cout << "\nTime of get is: " << secondsListTest3;

    double secondsListTest4 = (double(endTimeListTest4 - startTimeListTest4)) / CLOCKS_PER_SEC;
    cout << "\nTime of pop_front is: " << secondsListTest4;

    double secondsListTest5 = (double(endTimeListTest5 - startTimeListTest5)) / CLOCKS_PER_SEC;
    cout << "\nTime of pop_back is: " << secondsListTest5;

    double secondsList = (double(endTimeList - startTimeList)) / CLOCKS_PER_SEC;
    cout << "\nList run time is: " << secondsList;

    return 0;
}