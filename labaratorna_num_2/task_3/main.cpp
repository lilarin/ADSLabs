#include<iostream>
using namespace std;

int fibonacci(int number) {
    if (number < 2) {
        return 1;
    }
    return fibonacci(number-1) + fibonacci(number-2);
}
int main() {
    int n,amount=0;
    cin >> n;
    for (int count=0; count < n; ++count) {
        if (fibonacci(count)<n) {
            amount += 1;
        }
    }
    cout << amount << " ";
    return 0;
}