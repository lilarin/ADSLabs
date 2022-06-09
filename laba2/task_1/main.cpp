#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

bool isPrime(int number) {
    for(int divider=2; divider<=sqrt(number); divider++) {
        if ((number%divider) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int amountOfNumbers=0, SizeOfArray=1000, maxamountOfIterations=1000;
    int *arr = new int[SizeOfArray - 1];

    clock_t startTime = clock();
    for (int amountOfIterations=0; amountOfIterations < 1000; amountOfIterations++) {
        for (int i = 2; i <= SizeOfArray; i++) {
            arr[i - 2] = i;
        }

        for (int j = 2; j <= SizeOfArray; j++) {
            if (arr[j - 2] != 0) {
                if (j % 10 == 9 && j > 100) {
                }
                for (int k = j; k <= SizeOfArray; k += j) {
                    arr[k - 2] = 0;
                }
            }
        }
    }
    clock_t endTime = clock();

    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;

    //----------------------------------------------------------------

    clock_t startTimeBool = clock();
    for (int amountOfIterations=0; amountOfIterations<maxamountOfIterations; amountOfIterations++) {
        for (int number = 100; number <= SizeOfArray; number++) {
            if (isPrime(number) && number % 10 == 9) {
                //cout << number << "\t";
            }
        }
    }
    clock_t endTimeBool = clock();

    for(int number=2; number<=SizeOfArray; number++)
    {
        if (isPrime(number) && number % 10 == 9 && number > 100) {
            cout << number << "\t";
            amountOfNumbers += 1;
        }
    }

    cout <<"\nAmount of numbers that contain 9 as last digit and also prime: " << amountOfNumbers << " ";
    double secondsBool = (double (endTimeBool - startTimeBool)) / CLOCKS_PER_SEC;
    cout << "\n\nTime of work using method Sieve of Eratosthenes is: " << seconds;
    cout<< "\nTime of work using Enumeration of divisors: " << secondsBool;

    delete[] arr;
    return 1;
}