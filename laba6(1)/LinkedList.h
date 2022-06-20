//
// Created by User on 20.06.2022.
//

#ifndef MAIN_CPP_LINKEDLIST_H
#define MAIN_CPP_LINKEDLIST_H
using namespace std;

struct matanClassList {
    char surnameOfLecturer;
    int positionInOrder;
    int amountOfStudents;
};

struct Node {
    matanClassList data;
    Node* nextElement;
    //Node* previousElement;
};

struct LinkedList {
    Node* head;
    Node* tail;
    int size = 0;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(matanClassList *newData) {
        Node* node = new Node();
        node->data = *newData;
        node->nextElement = head;
        head = node;
        size++;
        if (size == 1) {
            tail = head;
        }
    }

    void push_back(matanClassList *newData) {
        Node* node = new Node();
        node->data = *newData;
        if (tail != nullptr) {
            tail->nextElement = node;
        }

        node->nextElement = nullptr;
        tail = node;
        size++;

        if (size == 1) {
            head = tail;
        }
    }

    matanClassList pop_front() {
        matanClassList temp = head->data;
        head = head->nextElement;
        size--;
        return temp;
    }

    matanClassList pop_back() {
        if (sizeOfList()==1) {
            matanClassList temp = head->data;
            return temp;
        }
        Node* node = head;
        matanClassList temp = tail->data;
        while (node->nextElement->nextElement != nullptr) {
            node = node->nextElement;
        }
        delete tail;
        node->nextElement = nullptr;
        tail = node;
        size--;
        return temp;
    }

    bool isEmpty() const {
        if (size==0) {
            return true;
        }
        return false;
    }

    void clear() {
        Node* node = head;
        Node* temp;
        while (node != nullptr)
        {
            temp = node;
            node = node->nextElement;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insert(matanClassList *newData,int position) {
        Node* node = head;
        Node* newNode = new Node();
        newNode->data = *newData;

        for (int i = 0; i < position - 1; i++) {
            node = node->nextElement;
        }
        newNode->nextElement = node->nextElement;
        node->nextElement = newNode;
        if (node->nextElement == nullptr) {
            tail = newNode;
        }
        size++;
    }

    matanClassList remove(int position) {
        Node* node = head;
        Node* temp;
        for (int i = 0; i < position - 1; i++) {
            node = node->nextElement;
        }
        temp = node;
        node = node->nextElement;
        temp->nextElement = node->nextElement;
        matanClassList returnObject = node->data;
        delete node;

        size--;
        return returnObject;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data.surnameOfLecturer << " " << current->data.positionInOrder << " " << current->data.amountOfStudents << endl;
            current = current->nextElement;
        }
    }

    matanClassList get(int position) const {
        Node* node = head;
        for (int i = 0; i <= position - 1; i++) {
            node = node->nextElement;
        }
        matanClassList temp = node->data;
        return temp;
    }

    int sizeOfList() const {
        return size;
    }

    Node* reverse() {
        if (head == nullptr || head->nextElement == nullptr) { // перев?рка, якщо список порожн?й, або м?стить 1 елемент
            return head;
        }
        Node* temp;
        Node* node = head;
        Node* nextNode = head->nextElement;
        head->nextElement = nullptr; // розвертаємо початок списку
        tail = head;
        while (nextNode != nullptr) {
            temp = nextNode->nextElement;
            nextNode->nextElement = node;
            node = nextNode;
            nextNode = temp;
        }
        head = node;
        return node;
    }

    ~LinkedList() {
        clear();
    }
};

#endif //MAIN_CPP_LINKEDLIST_H
