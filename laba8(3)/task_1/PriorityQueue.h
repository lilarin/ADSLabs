//
// Created by User on 12.06.2022.
//

#ifndef LABA8_PRIORITYQUEUE_H
#define LABA8_PRIORITYQUEUE_H

#include <vector>

using namespace std;

struct Data
{
    float distance;
    float health;

    bool operator < (const Data& secondUnit) const {
        if (distance != secondUnit.distance) {
            return distance < secondUnit.distance;
        }
        return health < secondUnit.health;
    }
    bool operator == (const Data& secondUnit) const {
        return distance == secondUnit.distance;
    }
    bool operator != (const Data& secondUnit) const {
        return distance != secondUnit.distance;
    }
    bool operator > (const Data& secondUnit) const {
        if (distance != secondUnit.distance) {
            return distance > secondUnit.distance;
        }
        return health > secondUnit.health;
    }
};


struct PriorityQueue {
    int size_;
    vector<Data> queue;

    int size() const {
        return size_;
    }

    bool isEmpty() const {
        return size() == 0;
    }

    static int getParent(int index) {
        return (index - 1) / 2;
    }

    static int getLeftChild(int index) {
        return (2 * index + 1);
    }

    static int getRightChild(int index) {
        return (2 * index + 2);
    }

    int getMaxChildIndex(int index) {
        if(queue[getLeftChild(index)] < queue[getRightChild(index)]) {
            return getRightChild(index);
        }
        return getLeftChild(index);
    }

    static bool IsRoot(int index) {
        return index == 0;
    }

    bool IsLeaf(int index) const {
        return getLeftChild(index) >= size();
    }

    void siftUp(int index) {
        if (IsRoot(index))
        {
            return;
        }
        Data self = queue[index];
        Data parent = queue[getParent(index)];
        if (self < parent) {
            return;
        }
        swap(self, parent);
        siftUp(getParent(index));
    }
    
    void siftDown(int index) {
        if (IsLeaf(index)) {
            return;
        }

        int maxChildIndex = getMaxChildIndex(index);

        if (queue[maxChildIndex] < queue[index]) {
            return;
        }
        
        swap(queue[maxChildIndex], queue[index]);
        siftDown(maxChildIndex);
    }

    void push(Data data) {
        queue.push_back(data);
        size_++;
        siftUp(size_ - 1);
    }

    Data top() {
        return queue.front();
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        swap(queue[0], queue[size_ - 1]);
        size_--;
        queue.erase(queue.end() - 1);
        siftDown(0);
    }
};

#endif //LABA8_PRIORITYQUEUE_H
