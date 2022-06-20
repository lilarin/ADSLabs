//
// Created by User on 06.06.2022.
//
#include "HashTable_Linear_Probing.h"

HashTable_Linear_Probing::HashTable_Linear_Probing() {
    capacity = 10;
    Size = 0;
    LoadFactor = 0.0f;
    LoadCapacity = 0.65f;
    Buckets = new Node[capacity];
    for (int i = 0; i < capacity; i++) {
        Buckets[i].statusCode = 0;
    }
}

long long HashTable_Linear_Probing::hash(long long key) const {
    return ((12 * key - 2) % 376258005738947) % capacity;
}

void HashTable_Linear_Probing::reallocate()
{
    int previousCapacity = capacity;
    capacity *= 2.0f;
    Node* TempBuckets = new Node[capacity];
    for (size_t i = 0; i < previousCapacity; i++)
    {
        Node& node = Buckets[i];
        if (node.statusCode == 1)
        {
            size_t index = hash(node.key);

            while (TempBuckets[index].statusCode == 1) {
                index = (index + 1) % capacity;
            }

            TempBuckets[index] = node;
        }
    }
    Buckets = TempBuckets;
}

void HashTable_Linear_Probing::insert(long long key, const Data& data)
{
    if ((LoadFactor = Size / capacity) > LoadCapacity) {
        reallocate();
    }

    size_t index = hash(key);
    while (Buckets[index].statusCode == 1)
    {
        Node& node = Buckets[index];
        if (node.key == key)
        {
            node.data = data;
            return;
        }
        index = (index + 1) % capacity;
    }

    Buckets[index] = {1, key, data};
    Size++;
}

Data* HashTable_Linear_Probing::find(unsigned long long key) const {
    size_t index = hash(key);
    while (Buckets[index].statusCode != 0) {
        Node& node = Buckets[index];
        if (node.key == key) {
            Data* ptr = nullptr;
            if (node.statusCode == 1)
                ptr = &node.data;
            return ptr;
        }
        index = (index + 1) % capacity;
    }
    return nullptr;
}

void HashTable_Linear_Probing::erase(unsigned long long key) {
    size_t index = hash(key);
    while (Buckets[index].statusCode != 0) {
        Node& node = Buckets[index];
        if (node.key == key) {
            if (node.statusCode == 1) {
                node.statusCode = 2;
                Size--;
            }

        }
        index = (index + 1) % capacity;
    }
}

int HashTable_Linear_Probing::size() const {
    return Size;
}

HashTable_Linear_Probing::~HashTable_Linear_Probing() {
    delete[] Buckets;
}
//


