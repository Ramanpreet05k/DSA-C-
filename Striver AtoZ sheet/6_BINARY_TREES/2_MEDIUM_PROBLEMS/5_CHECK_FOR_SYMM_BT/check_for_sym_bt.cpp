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

// 2. Class for your solution (Paste your LeetCode/CodingNinjas logic here)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return (root==nullptr) || isSymmetrichelp(root->left , root->right);
    }
    bool isSymmetrichelp(TreeNode* left,TreeNode* right){
        if(left==nullptr || right==nullptr){
            return left == right;
        }
        if(left->data != right->data) return false;

        return isSymmetrichelp(left->right, right->left) && isSymmetrichelp(left->left , right->right);
    }
};
// 3. Helper function to free memory (Good practice for local testing)
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
              2     2
             / \   / \
            4   5 4   4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Initialize your solution class
    Solution sol;
    if(sol.isSymmetric(root)){
        cout<<"It is symmeteric binary tree"<<endl;
    }
    else{
        cout<<"It is not symmetric binary tree"<<endl;
    }

    // Clean up memory before exiting
    deleteTree(root);

    return 0;
}