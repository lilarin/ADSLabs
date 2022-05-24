#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main() {
    int a;
    srand (time (NULL));
    a = rand() % 23;
    cout << a;
    return 0;
}
