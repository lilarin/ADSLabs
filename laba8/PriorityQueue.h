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
    bool operator<(const Data& other) const { return this->distance < other.distance; }
    bool operator>(const Data& other) const { return !(*this < other); }
    bool operator==(const Data& other) const { return this->distance == other.distance; }
    bool operator!=(const Data& other) const { return !(*this == other); }
};

struct PriorityQueue {
    int size;
    vector<Data> container;

    int Size() const {
        return size;
    }

    bool isEmpty() {
        return Size() == 0;
    }

    int getParent(int index) {
        return (index - 1) / 2;
    }

    int getLeftChild(int index) {
        return (2 * index + 1);
    }

    int getRightChild(int index) {
        return (2 * index + 2);
    }

    bool IsRoot(int index) {
        return index == 0;
    }

    bool IsLeaf(int index) {
        return getLeftChild(index) >= Size();
    }

    void siftUp(int index) {
        if (IsRoot(index))
        {
            return;
        }

        int parentIndex = getParent(index);
        Data self = container[index];
        Data parent = container[parentIndex];

        if (self < parent)
        {
            return;
        }

        std::swap(self, parent);
        siftUp(parentIndex);
    }
    void siftDown(int index) {
        // if true than this node is a leaf
        // if not, than at least left child exists
        if (IsLeaf(index))
        {
            return;
        }

        // Get left and right children
        int childIndex = getLeftChild(index);
        // Check if node at rightIndex exists
        if (childIndex + 1 < Size())
        {
            // ensure if right index is larger than left index
            childIndex = std::max<int>(childIndex, childIndex + 1,
                                            [&](const int& a, const int& b) -> bool
                                            {
                                                return container.at(a) < container.at(b);
                                            });
        }

        Data child = container.at(childIndex);
        Data self = container.at(index);

        if (child < self)
        {
            return;
        }

        swap(child, self);
        siftDown(childIndex);
    }
    void push(Data data) {
        container.push_back(data);
        size++;
        siftUp(Size() - 1);
    }

    Data top() {
        return container.front();
    }

    void pop() {
        if (isEmpty())
        {
            return;
        }
        swap(container[0], container[Size() - 1]);
        size--;
        container.erase(container.end() - 1);

        siftDown(0);
    }


};

#endif //LABA8_PRIORITYQUEUE_H
