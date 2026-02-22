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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == nullptr || q == nullptr){
            return (p==q);
        }
        return (p->data == q->data) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

       

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

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);


     TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    
    root2->right->left = new TreeNode(6);


    // Initialize your solution class
    Solution sol;
if (sol.isSameTree(root1, root2)) {
        cout << "Result: The trees are IDENTICAL." << endl;
    } else {
        cout << "Result: The trees are DIFFERENT." << endl;
    }

    // Clean up memory before exiting
    deleteTree(root1);
    deleteTree(root2);

    return 0;
}