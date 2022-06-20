//
// Created by User on 06.06.2022.
//

#ifndef MAIN_CPP_HASHTABLE_LINEAR_PROBING_H
#define MAIN_CPP_HASHTABLE_LINEAR_PROBING_H
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
};

struct Node
{
    int statusCode;
    long long key;
    Data data;
};

struct HashTable_Linear_Probing {
    Node* Buckets;
    int capacity;
    int Size;
    float LoadFactor;
    float LoadCapacity;

    HashTable_Linear_Probing();

    long long hash(long long key) const;

    void reallocate();

    void insert(long long key, const Data& data);

    Data* find(unsigned long long key) const;

    void erase(unsigned long long key);

    int size() const;

    ~HashTable_Linear_Probing();
};

#endif //MAIN_CPP_HASHTABLE_LINEAR_PROBING_H
