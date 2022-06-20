//
// Created by User on 25.04.2022.
//

#include "HashList.h"

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

void LinkedList::push_front(long long int Key, Data newData) {
    HashNode* node = new HashNode();
    node->data = newData;
    node->key = Key;
    node->next = head;
    head = node;
    size++;
}

bool LinkedList::remove(unsigned long long int Key) {
    HashNode* node = head;
    HashNode* temp = nullptr;
    while (node) {
        if (node->key == Key) {
            if (temp != nullptr) {
                temp->next = node->next;
            }
            else {
                head = node->next;
            }
            delete node;
            size--;
            return true;
        }
        temp = node;
        node = node->next;
    }
    return false;
}

Data* LinkedList::get(unsigned long long int Key) {
    HashNode* node = head;
    while (node) {
        if (node->key == Key) {
            return &node->data;
        }
        node = node->next;
    }
    return nullptr;
}

LinkedList::~LinkedList() {
    HashNode* node = head;
    while (head) {
        node = head;
        head = head->next;
        delete node;
    }
}
