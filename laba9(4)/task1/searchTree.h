//
// Created by User on 21.06.2022.
//

#ifndef TASK1_SEARCHTREE_H
#define TASK1_SEARCHTREE_H

using namespace std;

struct Data {
    int lvl;
    int daysPlayed;

    friend bool operator < (const Data &d1, const Data &d2) {
        return d1.lvl < d2.lvl;
    }

    friend bool operator == (const Data &d1, const Data &d2) {
        return d1.lvl == d2.lvl;
    }
};

struct Node {
    Data data;
    Node* left;
    Node* right;
};

struct BinarySearchTree {
    Node* root = nullptr;

    void insert(Data& data) {
        root = insertInner(root, data);
    }

    Node* insertInner(Node* node, Data& data) {
        if (!node) {
            return new Node{.data = data};
        }
        else if (data < node->data) {
            node->left = insertInner(node->left, data);
        }
        else if (node->data < data) {
            node->right = insertInner(node->right, data);
        }
        return node;
    }

    Node* minimum(Node* node) {
        if (!node->left) {
            return node;
        }
        return minimum(node->left);
    }

    void erase(Data& data) {
        eraseInner(root, data);
    }

    Node* eraseInner(Node* node, const Data& value) {
        if (!node) {
            return nullptr;
        }
        else if (value < node->data) {
            node->left = eraseInner(node->left, value);
        }
        else if (node->data < value) {
            node->right = eraseInner(node->right, value);
        }
        else {
            if (!node->left && !node->right) {
                delete node;
                node = nullptr;
            }
            else if (!node->left) {
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if (!node->right) {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            else if (node->left && node->right) {
                Node* temp = minimum(node->right);
                node->data = temp->data;
                node->right = eraseInner(node->right, temp->data);
            }
        }
        return node;
    }

    bool find(Data& data) {
        return findInner(root,data);
    }

    Node* findInner(Node* node, Data& data)
    {
        if (!node || node->data == data) {
            return node;
        }
        else if (data < node->data) {
            return findInner(node->left, data);
        }
        else {
            return findInner(node->right, data);
        }
    }

    int size() {
        return sizeInner(root);
    }

    int sizeInner(Node* node) {
        if (!node) {
            return 0;
        }
        size_t rightSize = sizeInner(node->right);
        size_t leftSize = sizeInner(node->left);
        return rightSize + leftSize + 1;
    }

    int height() {
        return heightInner(root);
    }

    int heightInner(Node* node) {
        if (!node) {
            return -1;
        }

        int rightHeight = heightInner(node->right);
        int leftHeight = heightInner(node->left);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else return rightHeight + 1;
    }
};

#endif //TASK1_SEARCHTREE_H
