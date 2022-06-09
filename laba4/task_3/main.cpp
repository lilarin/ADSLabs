#include <iostream>
using namespace std;

#define STACK_SIZE 255

struct Stack {

    char arr[STACK_SIZE];
    int top = -1;

    void push(char b) {
        if (top == STACK_SIZE - 1) {
            return;
        } else {
            top++;
            arr[top] = b;
        }
    }

    void pop() {
        if (isEmpty()) {
            return;
        } else {
            char b = arr[top];
            arr[top] = char();
            top--;
        }
    }

    bool isEmpty() const {
        return top == -1;
    }

    char getTop() {
        if (isEmpty()) {
            return arr[0];
        } else {
            return arr[top];
        }
    }
};

char getInverseBrace(char brace) {
    switch (brace) {
        case '{':
            return '}';
        case '(':
            return ')';
        case '[':
            return ']';
        default:
            return ' ';
    }
}

string braces(string braces,int length) {

    Stack st;
    for (int i = length - 1; i >= 0; i--) {
        if (st.getTop() == getInverseBrace(braces[i])) {
            st.pop();
        } else {
            st.push(braces[i]);
        }
    }

    if (st.isEmpty()) {
        return "yes";
    } else {
        return "no";
    }
}

int main() {
    string str;
    cin >> str;
    int length = str.length();
    if (length%2!=0) {
        cout << "no";
        return 0;
    }
    else {
        cout << braces(str, length);
    }
    return 0;
}