#include <iostream>
#include <cmath>
using namespace std;

int nToDec(int Number,int numbersInSystemN) {
    int rank,decNumber=0,currentNumber;
    rank = int(log10(Number)+1);
    for (int i=0; i<rank; i++) {
        currentNumber = Number % 10;
        decNumber = decNumber + int(pow(numbersInSystemN,i))*currentNumber;
        Number = Number / 10;
    }
    return decNumber;
}

int decToK(int numbersInSystemK,int decNumber) {
    int reminder, rank = 1, Number = 0;
    while (decNumber >= 1) {
        reminder = decNumber % numbersInSystemK;
        decNumber = decNumber / numbersInSystemK;
        Number = Number + reminder * rank;
        rank = rank * 10;
    }
    return Number;
}

int main() {
    int Number,numbersInSystemN,numbersInSystemK;
    cout << "Enter the number of characters in the first system (2-10):\n";
    cin >> numbersInSystemN;
    cout << "Enter the number of characters in the second system (2-10):\n";
    cin >> numbersInSystemK;
    cout << "Enter the number: " << endl;
    cin >> Number;
    nToDec(Number,numbersInSystemN);
    cout << Number << " in " << numbersInSystemN <<"-digit system equal to " << decToK(numbersInSystemK,nToDec(Number,numbersInSystemN)) << " in "<< numbersInSystemK<<"-digit system\n";

    return 0;
}