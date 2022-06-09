#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //Опис задачі:
    //Точка лежить на колі, якщо відстань від початку координат до точки < 1. Ця відстань - це гапотенуза
    //Знайти її можна за теоремою піфагора, понали.
    float x = 0; //Створюю змінні
    float y = 0;
    float distance;

    cout << endl << "Type x: ";// Отримую точки від користувача
    cin >> x;
    cout << endl << "Type y: ";
    cin >> y;

    //Записую вираз по якому обчислюю відстань від центру координат
    distance = sqrt(x*x + y*y);

    //Виводжу результат у консоль
    cout << endl << "Distance from (0,0) to point is: " << (distance);
    if (distance<=1)
        cout << endl << "Point lies on a circle";
    else
    cout << endl << "Point does not lie on the circle";

}
