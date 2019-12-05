#include<iostream>
#include<bits/stdc++.h>
class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int x) {
            data = x;
            left = nullptr;
            right = nullptr;
        }
};

bool isBST(Node *node, int min, int max);
int size(Node *root);
int check(Node *root);
void print(Node *root);
using namespace std;
int main() {
    Node *root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(8);

    root->left->left = new Node(12);
    root->left->right = new Node(20);

    root->right->left = new Node(5);
    root->right->right = new Node(2);

    // print(root);
    // cout << endl;

    cout << check(root) << endl;

    return 0;
}

int check(Node *root) {
    if(isBST(root, INT_MIN, INT_MAX))
            return size(root);
    
    return max(check(root->left), check(root->right));
}

bool isBST(Node *node, int min, int max) {
    if(node == nullptr)
        return true;
    
    if(node->data < min || node->data > max)
        return false;

    return isBST(node->left, min, node->data) &&
            isBST(node->right, node->data, max);
}

int size(Node *root) {
    if(root == nullptr)
        return 0;
    return 1+size(root->left)+size(root->right);
}

void print(Node *root) {
    if(!root)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}