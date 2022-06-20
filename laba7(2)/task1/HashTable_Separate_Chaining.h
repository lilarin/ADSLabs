//
// Created by User on 06.06.2022.
//
#include "HashList.h"

#ifndef MAIN_CPP_HASHTABLE_H
#define MAIN_CPP_HASHTABLE_H

struct HashTable_Separate_Chaining {
    LinkedList* Buckets;
    int capacity;
    int Size;
    float LoadFactor;
    float LoadCapacity;

    HashTable_Separate_Chaining();

    unsigned long long hash(unsigned long long key) const;

    void reallocate();

    void insert(long long key, const Data& data);

    Data* find(unsigned long long key) const;

    void erase(unsigned long long key);

    int size() const;

    ~HashTable_Separate_Chaining();
};

#endif //MAIN_CPP_HASHTABLE_H
