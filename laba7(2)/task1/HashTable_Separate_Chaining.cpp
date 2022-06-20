//
// Created by User on 06.06.2022.
//

#include "HashTable_Separate_Chaining.h"


HashTable_Separate_Chaining::HashTable_Separate_Chaining() {
    capacity = 10;
    Size = 0;
    LoadFactor = 0.0f;
    LoadCapacity = 0.9f;
    Buckets = new LinkedList[capacity];
}

unsigned long long HashTable_Separate_Chaining::hash(unsigned long long key) const
{
    return ((12 * key - 2) % 376258005738947) % capacity;
}

void HashTable_Separate_Chaining::reallocate()
{
    int previousCapacity = capacity;
    capacity *= 2.0f;

    LinkedList* TempBuckets;
    TempBuckets = new LinkedList[capacity];

    for (size_t i = 0; i < previousCapacity; i++)
    {
        LinkedList& list = Buckets[i];
        HashNode* node = list.head;
        while (node)
        {
            size_t index = hash(node->key);
            LinkedList& tempList = TempBuckets[index];
            if (list.get(node->key)) {
                tempList.push_front(node->key, node->data);
            }
            node = node->next;
        }
    }

    delete[] Buckets;
    Buckets = TempBuckets;
}


void HashTable_Separate_Chaining::insert(long long key, const Data& data)
{
    if ((LoadFactor = Size / capacity) > LoadCapacity) {
        reallocate();
    }

    unsigned long long index = hash(key);
    LinkedList& list = Buckets[index];
    if (!list.get(key)) {
        list.push_front(key, data);
        Size++;
    }
}

Data* HashTable_Separate_Chaining::find(unsigned long long key) const
{
    size_t index = hash(key);
    LinkedList& list = Buckets[index];
    return list.get(key);
}

void HashTable_Separate_Chaining::erase(unsigned long long key)
{
    size_t index = hash(key);
    LinkedList& list = Buckets[index];
    if (list.remove(key)) {
        Size--;
    }
}

int HashTable_Separate_Chaining::size() const {
    return Size;
}

HashTable_Separate_Chaining::~HashTable_Separate_Chaining()
{
    delete[] Buckets;
}


