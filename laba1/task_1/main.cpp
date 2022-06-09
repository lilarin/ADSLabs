#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //Додаю змінні
    float x;
    float y;
    double result;//Значення double використовую щоб виводити результат у множині раціональних чисел

    cout << endl << "Type x: "; //Користувач вводит свої x та y
    cin >> x;
    cout << endl << "Type y: ";
    cin >> y;

    //Задаю математичну функцію
    result = (sqrt(1+abs(x*y))-3*y)/(abs(sin(x*y)-x));

    //Виводжу результат у консоль
    cout << endl << "Result is: " << (result);


    return 1;
}
