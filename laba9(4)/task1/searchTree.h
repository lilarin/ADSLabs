//
// Created by User on 21.06.2022.
//

#ifndef TASK1_SEARCHTREE_H
#define TASK1_SEARCHTREE_H

using namespace std;

struct Data {
    int lvl;
    int daysPlayed;

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

//    Node* minimum(Node* node) {
//        Node *current = node;
//        // Find the leftmost leaf
//        while (current && current->left != NULL) {
//            current = current->left;
//        }
//
//        return current;
//    }

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
        else if (data < node->data) {
            node->left = eraseInner(node->left, data);
        }
        else if (node->data < data) {
            node->right = eraseInner(node->right, data);
        }
        else {
            // If the node is with only one child or no child
            if (!node->left) {
                Node *temp = node->right;
                free(node);
                return temp;
            }
            else if (!node->right) {
                Node *temp = node->left;
                free(node);
                return temp;
            }
            // If the node has two children
            Node *temp = minValueNode(node->right);
            // Place the inorder successor in position of the node to be deleted
            node->data = temp->data;
            // Delete the inorder successor
            node->right = eraseInner(node->right, temp->data);
        }
        return node;
    }

    Node* TEST_eraseInner(Node* node, Data& data) {
        if (!node) {
            return nullptr;
        }
        else if (data < node->data) {
            node->left = TEST_eraseInner(node->left, data);
        }
        else if (node->data < data) {
            node->right = TEST_eraseInner(node->right, data);
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
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = TEST_eraseInner(node->right, temp->data);
            }
        }
        return nullptr;
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
