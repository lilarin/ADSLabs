#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct matanClass {
    char surnameOfLecturer;
    int positionInOrder;
    int amountOfStudents;
};

struct DynamicArray {
    int max_size = 1000,current_size = 0;
    matanClass* arr = new matanClass[max_size];
    matanClass* tempArr;
    matanClass error;

    void reallocateMemory() {
        tempArr = new matanClass[max_size];

        for (int i = 0; i < current_size; i++) {
            tempArr[i] = arr[i];
        }
        delete [] arr;
        max_size = max_size * 2;
        arr = new matanClass[max_size];
        for (int i = 0; i < max_size / 2; i++) {
            arr[i] = tempArr[i];
        }
        delete [] tempArr;
    }

    bool checkIsFull() const {
        if (current_size >= max_size) {
            return true;
        }
        return false;
    }

    bool checkIsEmpty() const {
        if (current_size == 0) {
            return true;
        }
        return false;
    }

    void push_back(matanClass *data) {
        if (checkIsFull()) {
            reallocateMemory();
        }
        arr[current_size] = *data;
        current_size++;
    }

    void push_front(matanClass *data) {
        if (checkIsFull()) {
            reallocateMemory();
        }
        for (int i = current_size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = *data;
        current_size++;
    }

    matanClass pop_back() {
        if (checkIsEmpty()) {
            return error;
        }
        current_size--;
        matanClass temp = arr[current_size];
        return temp;
    }

    matanClass pop_front() {
        if (checkIsEmpty()) {
            return error;
        }
        matanClass temp = arr[0];
        for (int i = 0; i < current_size-1; i++) {
            arr[i] = arr[i+1];
            if (i == current_size-1) {
                arr[current_size] = temp;
            }
        }
        current_size--;
        return temp;
    }

    matanClass get(int number) const {
        matanClass temp = arr[number];
        return temp;
    }

    void insert(matanClass *data,int position) {
        if (checkIsFull()) {
            reallocateMemory();
        }
        for (int i = current_size; i > position; i--) {
            arr[i] = arr[i-1];
        }
        arr[position] = *data;
        current_size++;
    }

    void remove(int position) {
        for (int i = position; i < current_size; i++) {
            arr[i] = arr[i+1];
        }
        current_size--;
    }

    int sizeOfArray() const {
        return current_size;
    }

    int capacity() const {
        return max_size;
    }

    void print() const {
        matanClass temp;
        for (int i = 0; i < current_size; i++) {
            temp = get(i);
            cout << temp.surnameOfLecturer << " " << temp.positionInOrder << " " << temp.amountOfStudents << endl;
        }
    }

    void clear() {
        current_size = 0;
        delete [] arr;
    }
    ~DynamicArray() {
        delete[] arr;
    }
};


struct Node {
    matanClass data;
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


    void push_front(matanClass *newData) {
        Node* node = new Node();
        node->data = *newData;
        node->nextElement = head;
        head = node;
        size++;
        if (size == 1) {
            tail = head;
        }
    }

    void push_back(matanClass *newData) {
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

    matanClass pop_front() {
        matanClass temp = head->data;
        head = head->nextElement;
        size--;
        return temp;
    }

    matanClass pop_back() {
        if (sizeOfList()==1) {
            matanClass temp = head->data;
            return temp;
        }
        Node* node = head;
        matanClass temp = tail->data;
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

    void insert(matanClass *newData,int position) {
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

    matanClass remove(int position) {
        Node* node = head;
        Node* temp;
        for (int i = 0; i < position - 1; i++) {
            node = node->nextElement;
        }
        temp = node;
        node = node->nextElement;
        temp->nextElement = node->nextElement;
        matanClass returnObject = node->data;
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

    matanClass get(int position) const {
        Node* node = head;
        for (int i = 0; i <= position - 1; i++) {
            node = node->nextElement;
        }
        matanClass temp = node->data;
        return temp;
    }

    int sizeOfList() const {
        return size;
    }

    Node* reverse() {
        if (head == nullptr || head->nextElement == nullptr) { // перевірка, якщо список порожній, або містить 1 елемент
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

int main() {
    DynamicArray method;
    LinkedList list;
    srand(time(nullptr));
    int i=0;
    // vector
    clock_t startTimeVector = clock();
    clock_t startTimeVectorTest1 = clock();
    while (i++ < 50000) {
        matanClass data = {'t', 1, 1};
        method.push_back(&data);
    }
    clock_t endTimeVectorTest1 = clock();
    i=0;

    clock_t startTimeVectorTest2 = clock();
    while (i++ < 10000) {
        matanClass data = {'t', 1, 1};
        method.push_front(&data);
    }
    clock_t endTimeVectorTest2 = clock();
    i=0;

    clock_t startTimeVectorTest3 = clock();
    while (i++ < 20000) {
        int n = rand() % 59999 + 1;
        method.get(n);
    }
    clock_t endTimeVectorTest3 = clock();
    i=0;

    clock_t startTimeVectorTest4 = clock();
    while (i++ < 5000) {
        method.pop_front();
    }
    clock_t endTimeVectorTest4 = clock();
    i=0;

    clock_t startTimeVectorTest5 = clock();
    while (i++ < 5000) {
        method.pop_back();
    }
    clock_t endTimeVectorTest5 = clock();
    clock_t endTimeVector = clock();
    i=0;

    double secondsVectorTest1 = (double(endTimeVectorTest1 - startTimeVectorTest1)) / CLOCKS_PER_SEC;
    cout << "Time of push_back is: " << secondsVectorTest1;

    double secondsVectorTest2 = (double(endTimeVectorTest2 - startTimeVectorTest2)) / CLOCKS_PER_SEC;
    cout << "\nTime of push_front is: " << secondsVectorTest2;

    double secondsVectorTest3 = (double(endTimeVectorTest3 - startTimeVectorTest3)) / CLOCKS_PER_SEC;
    cout << "\nTime of get is: " << secondsVectorTest3;

    double secondsVectorTest4 = (double(endTimeVectorTest4 - startTimeVectorTest4)) / CLOCKS_PER_SEC;
    cout << "\nTime of pop_front is: " << secondsVectorTest4;

    double secondsVectorTest5 = (double(endTimeVectorTest5 - startTimeVectorTest5)) / CLOCKS_PER_SEC;
    cout << "\nTime of pop_back is: " << secondsVectorTest5;

    double secondsVector = (double(endTimeVector - startTimeVector)) / CLOCKS_PER_SEC;
    cout << "\nArray run time is: " << secondsVector;


    // list
    clock_t startTimeList = clock();
    clock_t startTimeListTest1 = clock();
    while (i++ < 50000) {
        matanClass data = {'t', 1, 1};
        list.push_back(&data);
    }
    clock_t endTimeListTest1 = clock();
    i=0;

    clock_t startTimeListTest2 = clock();
    while (i++ < 10000) {
        matanClass data = {'t', 1, 1};
        list.push_front(&data);
    }
    clock_t endTimeListTest2 = clock();
    i=0;

    clock_t startTimeListTest3 = clock();
    while (i++ < 20000) {
        int n = rand() % 59999 + 1;
        list.get(n);
    }
    clock_t endTimeListTest3 = clock();
    i=0;

    clock_t startTimeListTest4 = clock();
    while (i++ < 5000) {
        list.pop_front();
    }
    clock_t endTimeListTest4 = clock();
    i=0;

    clock_t startTimeListTest5 = clock();
    while (i++ < 5000) {
        list.pop_back();
    }
    clock_t endTimeListTest5 = clock();
    clock_t endTimeList = clock();


    double secondsListTest1 = (double(endTimeListTest1 - startTimeListTest1)) / CLOCKS_PER_SEC;
    cout << "\n\nTime of push_back is: " << secondsListTest1;

    double secondsListTest2 = (double(endTimeListTest2 - startTimeListTest2)) / CLOCKS_PER_SEC;
    cout << "\nTime of push_front is: " << secondsListTest2;

    double secondsListTest3 = (double(endTimeListTest3 - startTimeListTest3)) / CLOCKS_PER_SEC;
    cout << "\nTime of get is: " << secondsListTest3;

    double secondsListTest4 = (double(endTimeListTest4 - startTimeListTest4)) / CLOCKS_PER_SEC;
    cout << "\nTime of pop_front is: " << secondsListTest4;

    double secondsListTest5 = (double(endTimeListTest5 - startTimeListTest5)) / CLOCKS_PER_SEC;
    cout << "\nTime of pop_back is: " << secondsListTest5;

    double secondsList = (double(endTimeList - startTimeList)) / CLOCKS_PER_SEC;
    cout << "\nList run time is: " << secondsList;

    return 0;
}