#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n; //Створюю змінні
    double sum = 0;

    cout << "\nType n:";//Користувач вводить верхню межу суми
    cin >> n;
    int k = 1;

    while (k <= n) { //Створюю цикл для разрахунку суми
        sum =+ pow(-1, k) / (pow(k, 2) * (k + 1));
        k++;
    }
    cout << "\nSum is: " << sum << endl; //Виводжу результат у консоль
    return 1;
}
