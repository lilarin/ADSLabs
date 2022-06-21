//
// Created by User on 21.06.2022.
//

#ifndef TASK1_SEARCHTREE_H
#define TASK1_SEARCHTREE_H
#include <vector>

using namespace std;

struct Data {
//    int lvl = rand();
//    int daysPlayed = rand();
    int lvl;
    int daysPlayed;

    Data()
        : lvl (rand())
        , daysPlayed(rand())
    {
    }

    bool operator < (const Data &d2) const {
        if (lvl != d2.lvl) {
            return lvl < d2.lvl;
        }
        else return daysPlayed < d2.daysPlayed;
    }

    bool operator == (const Data &d2) const {
        return lvl == d2.lvl && daysPlayed == d2.daysPlayed;
    }
};

struct Node {
    Data data;
    Node* left;
    Node* right;
};

struct BinarySearchTree {
    Node* root = nullptr;

//    BinarySearchTree() {
//            root->data;
//            root->right;
//            root->left;
//    }


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

    Node* minValueNode(Node *node) {
        if (!node->left) {
            return node;
        }
        return minValueNode(node->left);
    }

    void erase(Data& data) {
        eraseInner(root, data);
    }

    Node* eraseInner(Node* node, Data& data){

        // Return if the tree is empty
        if (!node) {
            return nullptr;
        }
        // Find the node to be deleted
        if (data < node->data) {
            node->left = eraseInner(node->left, data);
        }
        else if (node->data < data) {
            node->right = eraseInner(node->right, data);
        }
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
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
            else if (node->right && node->left) {
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = eraseInner(node->right,temp->data);
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


    vector<Data> findInRange(const Data& left, const Data& right) {
        vector<Data> vector;
        innerFindInRange(vector, root, left, right);
        return vector;
    }

    void innerFindInRange(vector<Data>& vector, Node* node, const Data& left, const Data& right) {
        if (!node) {
            return;
        }
        else if(node->data < left) {
            innerFindInRange(vector, node->right, left, right);
        }
        else if(right < node->data) {
            innerFindInRange(vector, node->left, left, right);
        }
        else {
            vector.push_back(node->data);
            innerFindInRange(vector, node->left, left, right);
            innerFindInRange(vector, node->right, left, right);
        }
    }


    void clear(Node* node) {
        if (!node) {
            return;
        }
        if (node->left) {
            clear(node->left);
        }
        if (node->right) {
            clear(node->right);
        }
        node = nullptr;
        delete node;
    }

    ~BinarySearchTree() {
        clear(root);
    }

};

#endif //TASK1_SEARCHTREE_H
