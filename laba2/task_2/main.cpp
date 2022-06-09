#include <iostream>
#include <cmath>
using namespace std;

int decToOct(int decNumber) {
    int reminder, rank = 1, octNumber = 0;
    while (decNumber >= 1) {
        reminder = decNumber % 8;
        decNumber = decNumber / 8;
        octNumber = octNumber + reminder * rank;
        rank = rank * 10;
    }
    return octNumber;
}

int OctToDec(int octNumber) {
    int rank,decNumber=0,currentNumber;
    rank = int(log10(octNumber)+1);
    for (int i=0; i<rank; i++) {
        currentNumber = octNumber % 10;
        decNumber = decNumber + int(pow(8,i))*currentNumber;
        octNumber = octNumber / 10;
    }
    return decNumber;
}

int main() {
    int decNumber,octNumber;
    int a;
    cout << "Type 1 to transform Octal in Decimal or 2 to transform from Decimal in Octal" << endl;
    cin >> a;
    switch (a) {
        case 1:
            cout << "Enter an octal number:\n";
            cin >> octNumber;
            cout << octNumber << " in octal equal to " << OctToDec(octNumber) << " in decimal";
            break;
        case 2:
            cout << "Enter a decimal number:";
            cin >> decNumber;
            cout << decNumber << " in decimal equal to " << decToOct(decNumber) << " in octal";
            break;
        default:
            cout << "Invalid value." << endl;
            break;
    }
    return 0;
}