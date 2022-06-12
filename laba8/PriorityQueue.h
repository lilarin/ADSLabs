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
    int size;
    vector<Data> queue;

    int Size() const {
        return size;
    }

    bool isEmpty() const {
        return Size() == 0;
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

    static bool IsRoot(int index) {
        return index == 0;
    }

    bool IsLeaf(int index) const {
        return getLeftChild(index) >= Size();
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

        int maxChildIndex = max(getLeftChild(index), getRightChild(index));

        if (queue[maxChildIndex] < queue[index]) {
            return;
        }
        swap(queue[maxChildIndex], queue[index]);
        siftDown(maxChildIndex);
    }

    void push(Data data) {
        queue.push_back(data);
        size++;
        siftUp(size - 1);
    }

    Data top() {
        return queue.front();
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        swap(queue[0], queue[size - 1]);
        size--;
        queue.erase(queue.end() - 1);
        siftDown(0);
    }
};

#endif //LABA8_PRIORITYQUEUE_H
