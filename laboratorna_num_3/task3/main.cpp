#include <iostream>
#include <iomanip>
using namespace std;
double function(double a, double b, double x);
double ternarySearch(double a, double b,double leftBorder,double rightBorder,double EPS);

int main() {
    int a, b,leftBorder=-100,rightBorder=100;
    double EPS = 0.0001;
    cout << "Type a and b:";
    cin >> a >> b;
    cout << "" << fixed << setprecision(2) << ternarySearch(a,b,leftBorder,rightBorder,EPS);
    return 0;
}
double function(double a, double b, double x)
{
    double value = x * x + a * x + b;
    return value;
}
double ternarySearch(double a, double b,double leftBorder,double rightBorder,double EPS)
{
    while (rightBorder - leftBorder > EPS)
    {
        double left = leftBorder + (rightBorder - leftBorder) / 3;/*Тут ми обираємо точки m1 та m2. Вибрати можна іншими способами*/
        double right = rightBorder - (rightBorder - leftBorder) / 3;/*Від цього буде залежати швидкість сходження*/
        if (function(a, b, left) < function(a, b, right)) {
            rightBorder = right;
        }
        else {
            leftBorder = left;
        }
    }
    return (rightBorder + leftBorder) / 2;
}
