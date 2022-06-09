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
    // 0 - empty, 1 - full, 2 - reserved
    long long key;
    Data data;
};

struct HashTable_Linear_Probing {
    Node* Buckets;
    int capacity;
    int Size;
    float LoadFactor;
    float LoadCapacity;


    HashTable_Linear_Probing() {
        capacity = 10;
        Size = 0;
        LoadFactor = 0.0f;
        LoadCapacity = 0.65f;
        Buckets = new Node[capacity];
        for (int i = 0; i < capacity; i++) {
            Buckets[i].statusCode = 0;
        }
    }

    long long hash(long long key) const
    {
        return ((12 * key - 2) % 376258005738947) % capacity;
    }

    void reallocate()
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


    void insert(long long key, const Data& data)
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

    Data* find(unsigned long long key) const
    {
        size_t index = hash(key);
        while (Buckets[index].statusCode != 0)
        {
            Node& node = Buckets[index];
            if (node.key == key)
            {
                Data* ptr = nullptr;
                if (node.statusCode == 1)
                    ptr = &node.data;
                return ptr;
            }
            index = (index + 1) % capacity;
        }
        return nullptr;
    }

    void erase(unsigned long long key)
    {
        size_t index = hash(key);
        while (Buckets[index].statusCode != 0)
        {
            Node& node = Buckets[index];
            if (node.key == key)
            {
                if (node.statusCode == 1)
                {
                    node.statusCode = 2;
                    Size--;
                }

            }
            index = (index + 1) % capacity;
        }
    }

    int size() const {
        return Size;
    }

    ~HashTable_Linear_Probing()
    {
        delete[] Buckets;
    }
};



#endif //MAIN_CPP_HASHTABLE_LINEAR_PROBING_H
