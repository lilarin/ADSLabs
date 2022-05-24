//
// Created by User on 25.04.2022.
//

#ifndef MAIN_CPP_HASHLIST_H
#define MAIN_CPP_HASHLIST_H

#include <iostream>
using namespace std;

struct Data {
    string name;
    string subject;
    string microphoneQuality;
};

struct HashNode {
    long long key;
    Data data;
    HashNode* next;
};

struct LinkedList {
    HashNode* head;
    int size;

    LinkedList();

    void push_front(long long int Key, Data newData);

    bool remove(unsigned long long int Key);

    Data* get(unsigned long long int Key);

    ~LinkedList();
};

#endif //MAIN_CPP_HASHLIST_H
