#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode {
    public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

BinaryTreeNode<int> *lcaofThreeNodes(BinaryTreeNode<int> *root, int node1, int node2, int node3) {
    // Check if the current node is one of the nodes and return the same
    if(!root || root->data == node1 || root->data == node2 || root->data == node3) {
        return root;
    }

    // compute lca in the left and right subtrees of the current root
    BinaryTreeNode<int> *left = lcaofThreeNodes(root->left, node1, node2, node3);
    BinaryTreeNode<int> *right = lcaofThreeNodes(root->right, node1, node2, node3);
    
    // if there exist left or right subtree then return either if one,
    // else if both are present return the current root
    if(!left) return right;
    else if(!right) return left;
    else return root;
}


int main() {
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(4);
    root->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    BinaryTreeNode<int> *lca = lcaofThreeNodes(root, 3, 6, 7);
    cout << lca->data << "\n";
    return 0;
}
