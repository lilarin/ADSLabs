#include <iostream>
#include <string>
using namespace std;
#define STACK_SIZE 6

struct Book {
    string name;
    int pages;
    int price;
};

struct Stack {
    Book arr[STACK_SIZE];
    Book empty = {};
    Book temp;
    int top = -1;

    void push(Book *info) {
        if (top == STACK_SIZE - 1) {
            cout << "Stack overflow" << endl;
        } else {
            top++;
            arr[top] = *info;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    Book pop() {
        if (isEmpty()) {
            return empty;
        } else {
            temp = arr[top];
            arr[top] = empty;
            top--;
            return temp;
        }
    }

    Book topValue() {
        if (isEmpty()) {
            return empty;
        } else {
            temp = arr[top];
            return temp;
        }
    }
    int size() {
        return top+1;
    }
    void clear() {
        if (!isEmpty()) {
            top = -1;
        }
    }

};


void display(Stack shelf) {
    while (!shelf.isEmpty()){
        Book temp = shelf.pop();
        cout << temp.name << " " << temp.pages << " " << temp.price <<"$" << endl;
    }
}


int main() {

    Stack shelf;
    int menu;
    cout << "\t\tMenu\n" << "\t[ 1. Push element   ]\n" << "\t[ 2. Pop element    ]\n" << "\t[ 3. Print stack    ]\n" << "\t[ 4. Size of stack  ]\n" << "\t[ 5. Clear stack    ]\n" << "\t[ 6. Top element    ]\n" << "\t[ 7. Is empty?      ]\n"<< "\t[ 8. Remove 4 pages ]\n"<< "\t[ 9. Exit           ]\n";
    do {
        cin >> menu;
        if (menu==1) {
            string name;
            int pages,price,repeats=0;
            cout << "Type amount of elements to add.\n";
            cin >> repeats;
            cout << "Type:  Book, pages and price.\n";
            for (int i=0; i<repeats; i++) {
                cin >> name >> pages >> price;
                Book info = {name, pages, price};
                shelf.push(&info);
            }

        }
        if (menu==2) {
            Book temp = shelf.pop();
            if (temp.name==shelf.empty.name) {
                cout << "Stack is empty.\n";
            }
            else {
                cout << "Last book was deleted.\n";
                cout << temp.name << " " << temp.pages << " " << temp.price <<"$" << endl;
            }
        }
        if (menu==3) {
            if (shelf.size()<1) {
                cout << "Stack is empty.\n";
            }
            else {
                int counter=0;
                cout << "Stack was printed.\n";
                display(shelf);
            }

        }
        if (menu==4) {
            cout << "Size of Stack is: ";
            cout << shelf.size() << endl;
        }
        if (menu==5) {
            if (shelf.top==-1) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Stack was cleared.\n";
                shelf.clear();
            }
        }
        if (menu==6) {
            if (shelf.isEmpty()) {
                cout << "Stack is empty.\n";
            }
            else {
                Book top = shelf.topValue();
                cout << "Top value is:\n";
                cout << top.name << " " << top.pages << " " << top.price <<"$"<< endl;
            }
        }
        if (menu==7) {
            if (shelf.isEmpty()) {
                cout << "Yes.\n";
            }
            else {
                cout << "No.\n";
            }
        }
        if (menu==8) {
            if (shelf.topValue().pages < 4 || shelf.size()==0) {
                cout << "I can not remove pages.\n";
            }
            else {
                cout << "Pages removed.\n";
                Book temp = shelf.topValue();
                temp.pages -= 4;
                shelf.topValue() = temp;
            }
        }

    }
    while (menu!=9);
    return 1;
}