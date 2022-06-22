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

    Data()
        : distance(static_cast<float>(rand()))
        , health(static_cast<float>(rand()))
    {}



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

    int Size;
    vector<Data> queue;

    PriorityQueue():Size(0) {}

    int size() const {
        return Size;
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
        if(queue.at(getLeftChild(index)) < queue.at(getRightChild(index))) {
            return getRightChild(index);
        }
        return getLeftChild(index);
    }

    static bool isRoot(int index) {
        return index <= 0;
    }

    bool isLeaf(int index) const {
        return getLeftChild(index) >= size();
    }

    void siftUp(int index) {
        if (isRoot(index)) {
            return;
        }
        Data& self = queue[index];
        Data& parent = queue[getParent(index)];
        if (!(self < parent)) {
            swap(self, parent);
            siftUp(getParent(index));
        }
    }
    
    void siftDown(int index) {
        if (isLeaf(index)) {
            return;
        }

        int maxChildIndex;
        if (getLeftChild(index) + 1 < Size) {
            maxChildIndex = getMaxChildIndex(index);
        }
        else {
            maxChildIndex = getLeftChild(index);
        }

        if (queue[maxChildIndex] < queue[index]) {
            return;
        }
        swap(queue[maxChildIndex], queue[index]);
        siftDown(maxChildIndex);
    }

    void push(const Data& data) {
        queue.push_back(data);
        Size++;
        siftUp(Size - 1);
    }

    Data top() {
        return queue.front();
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        iter_swap(queue.begin(), queue.end()-1);
        Size--;
        queue.erase(queue.end() - 1);
        siftDown(0);
    }
};

#endif //LABA8_PRIORITYQUEUE_H
