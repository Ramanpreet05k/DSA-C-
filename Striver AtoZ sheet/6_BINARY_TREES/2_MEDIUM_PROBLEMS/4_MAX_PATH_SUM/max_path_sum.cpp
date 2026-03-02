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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxpath(root,maxi);
        return maxi;
    }
    int maxpath(TreeNode* node, int &maxi){
        if(node == nullptr) return 0;
        int lh = max(0,maxpath(node->left,maxi));
        int rh = max(0,maxpath(node->right,maxi));
        maxi = max( maxi, lh+rh+ node->data);
        return max(lh,rh)+(node->data);
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

    cout << "Max path sum of Binary Tree: "<< sol.maxPathSum(root);
    cout << endl;

    // Clean up memory before exiting
    deleteTree(root);

    return 0;
}