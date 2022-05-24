#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long long lastnum=1000000000000;
    long lastnumforarr;
    lastnumforarr = (lastnum - 1)/2+1;
    long long *arr = new long long[lastnumforarr];
    clock_t startTime = clock();
// тут код, час виконання якого замірюється
    arr[0] = 2;
    for (int number = 3,j=2; number <= lastnum; number+=2,j++) { // записует числа от 2 до последнего числа в массив
        arr[number - j] = number;
    }
    for (int placeofnum = 1,step = 3; placeofnum < lastnumforarr; placeofnum++ , step += 2) { // решето эратосфена
        if (arr[placeofnum] != 0) {  // вывод числа если оно не 0
            for (int i = placeofnum+step; i < lastnumforarr; i += step) { // число, и шаг которий равен числу
                arr[i] = 0;// после каждого шага число становится 0
            }
        }
    }
    clock_t endTime = clock();
    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
    cout << "time:" << seconds << endl;

    return 0;
}