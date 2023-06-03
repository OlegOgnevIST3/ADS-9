// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BinarySearchTree {
 private:
    struct Node {
        T value;
        int count;
        Node *left, *right;
    };
    Node* root;
    Node* AddNode(Node* root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = AddNode(root->left, value);
        } else if (root->value < value) {
            root->right = AddNode(root->right, value);
        } else {
            root->count += 1;
        }
        return root;
    }
    int HeightTree(Node* root) {
        if (root == nullptr) return 0;
        return std::max(HeightTree(root->left), HeightTree(root->right)) + 1;
    }
    Node* SearchTree(Node* root, const T& value) {
        if (root == nullptr || root->value == value) return root;
        if (value < root->value) return SearchTree(root->left, value);
        return SearchTree(root->right, value);
    }

 public:
    BinarySearchTree() : root(nullptr) {}
    void Add(const T& value) { root = AddNode(root, value); }
    int Depth() { return HeightTree(root) - 1; }
    int Search(const T& value) {
        Node* current = SearchTree(root, value);
        if (current == nullptr) {
            return 0;
        } else {
            return current->count;
        }
    }
};
#endif  // INCLUDE_BST_H_
