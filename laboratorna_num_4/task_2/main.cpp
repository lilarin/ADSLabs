#include <iostream>
#include <string>
using namespace std;
#define QUEUE_SIZE 5

struct Item {
    string name;
    int price;
    int expiration;
};

struct Queue {
    Item arr[QUEUE_SIZE];
    Item empty = {};
    int front = 0,rear = 0;

    void push(Item *info) {
        if (rear == QUEUE_SIZE)
            cout << "Queue Overflow" << endl;
        else {
            rear++;
            arr[rear] = *info;
        }
    }

    bool isEmpty() const {
        return front == rear;
    }

    Item pop() {
        if (isEmpty()) {
            return empty;
        } else {
            front++;
            Item temp = arr[front];
            return temp;
        }
    }
    Item frontValue() {
        if (isEmpty()) {
            return empty;
        } else {
            Item temp = arr[front+1];
            return temp;
        }
    }
    int size() const {
        return rear - front;
    }
    void clear() {
        if (!isEmpty()) {
            front = 0;
            rear = 0;
        }
    }

    void sale() {
        arr[front+1].price = arr[front+1].price / 4 * 3;
    }
};

void display(struct Queue items) {
    int counter=0;
    while (items.front < items.rear) {
        Item print = items.pop();
        counter++;
        cout << print.name << " " << print.price << "$ " << print.expiration << " days" << endl;
    }
    items.front -= counter;
}


int main() {

    Queue items;

    int menu;
    cout << "\t\tMenu\n" << "\t[ 1. Push element   ]\n" << "\t[ 2. Pop element    ]\n" << "\t[ 3. Print queue    ]\n" << "\t[ 4. Size of queue  ]\n" << "\t[ 5. Clear queue    ]\n" << "\t[ 6. Front element  ]\n" << "\t[ 7. Is empty?      ]\n"<< "\t[ 8. Sale 25%       ]\n"<< "\t[ 9. Exit           ]\n";
    do {
        cin >> menu;
        if (menu==1) {
            string name;
            int price,expiration,repeats=0;
            cout << "Type amount of elements to add.\n";
            cin >> repeats;
            cout << "Type item, price and amount of day to expiration\n";
            for (int i=0; i<repeats; i++) {
                cin >> name >> price >> expiration;
                Item info = {name, price, expiration};
                items.push(&info);
            }
        }
        if (menu==2) {
            Item temp = items.pop();
            if (temp.name == items.empty.name) {
                cout << "Queue is empty.\n";
            }
            else {
                cout << "Last item was deleted.\n";
                cout << temp.name << " " << temp.price << "$ " << temp.expiration << " days" <<endl;
            }
        }
        if (menu==3) {
            if (items.isEmpty()) {
                cout << "Queue is empty.\n";
            }
            else {
                cout << "Stack was printed.\n";
                display(items);
            }

        }

        if (menu==4) {
            if (items.isEmpty()) {
                cout << "Queue is empty.\n";
            } else {
                cout << "Size of queue is:\n";
                cout << items.size() << endl;
            }
        }
        if (menu==5) {
            cout << "Queue cleared\n";
            items.clear();
        }
        if (menu==6) {
            if (items.isEmpty()) {
                cout << "Queue is empty.\n";
            } else {
                cout << "Front value is:\n";
                cout << items.frontValue().name << " " << items.frontValue().price << "$ " << items.frontValue().expiration << " days" << endl;
            }
        }
        if (menu==7) {
            if (items.isEmpty()) {
                cout << "Yes.\n";
            } else {
                cout << "No.\n";
            }
        }
        if (menu==8) {
            items.sale();
            cout << "Discount applied.\n";
        }
        if (menu==0) {
            //For Debug
            cout << "rear:" << items.rear << "front:" << items.front<< endl;
        }
    }
    while (menu!=9);

    return 0;
}