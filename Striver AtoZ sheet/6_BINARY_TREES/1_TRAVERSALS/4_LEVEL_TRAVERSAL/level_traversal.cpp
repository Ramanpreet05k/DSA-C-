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

// 2. Class for your solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> currentlevel;
            
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                currentlevel.push_back(node->data);

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            ans.push_back(currentlevel);
        }
        return ans;
    }
};

// 3. Helper function to free memory
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

    cout << "Level Order Traversal output:" << endl;
    vector<vector<int>> ans = sol.levelOrder(root);
    
    // FIX: Iterate through the 2D vector to print it
    for (int i = 0; i < ans.size(); i++) {
        cout << "Level " << i << ": [ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }

    // Clean up memory before exiting
    deleteTree(root);

    return 0;
}