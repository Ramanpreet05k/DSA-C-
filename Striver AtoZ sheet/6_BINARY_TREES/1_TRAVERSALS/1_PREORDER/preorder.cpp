#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1. Node Definition
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
public:
 
    void preorder(TreeNode* root) {
        if (root == nullptr) return;
          cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
};


void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// 4. Main function for local execution
int main() {
    /* Let's manually build this tree for testing:
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Initialize your solution class
    Solution sol;

    cout << "Preorder Traversal output: ";
    sol.preorder(root);
    cout << endl;

    // Clean up memory before exiting
    deleteTree(root);

    return 0;
}