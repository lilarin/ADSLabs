#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    const int numbers = 50;
    int mas[numbers]{}; //Створюю масив з 50 комірками

    for (int n = 0; n < numbers; n++) //Заповнюю масив за допомогою функції "псевдо-рандому"?
    {
        mas[n] = -50 + rand() % 101;
        cout<< mas[n] << " ";
    }
    cout<< "\n\n<-------------------------------------------\n\n";
    for (int n = numbers -1; n >= 0; n--) //Виводжу масив з кінця з кроком -1
    {
        cout<< mas[n] << " ";
    }
    return 1;
}