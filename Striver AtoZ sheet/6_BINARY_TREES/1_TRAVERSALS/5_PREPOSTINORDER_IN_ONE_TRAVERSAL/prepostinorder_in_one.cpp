#include <iostream>
#include <vector>
#include <queue>
#include <stack> // FIX 1: Added missing stack header

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
class Solution{
    public:
        vector<vector<int>> treeTraversal(TreeNode* root){
            stack<pair<TreeNode*,int>> st;
            vector<vector<int>> ans;
            vector<int> pre, inor, post;
            
            if(root == nullptr) return ans;
            
            st.emplace(root, 1); 
            
            while(!st.empty()){
                auto it = st.top();
                st.pop();
                
                if(it.second == 1){
                    pre.push_back(it.first->data);
                    it.second++;
                    st.push(it); 
                    
                    if(it.first->left != nullptr){
                        st.emplace(it.first->left, 1); 
                    }
                }
                else if(it.second == 2){
                    inor.push_back(it.first->data);
                    it.second++;
                    st.push(it); 
                    
                    if(it.first->right != nullptr){
                        st.emplace(it.first->right, 1); 
                    }
                }
                else{
                    post.push_back(it.first->data);
                }
            }
            
            ans.push_back(inor);
            ans.push_back(pre);
            ans.push_back(post);

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
    /* Manually built tree:
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

    Solution sol;

    cout << "Pre, In, and Post Order in one traversal:" << endl;
    vector<vector<int>> ans = sol.treeTraversal(root);
    
    // Optional: Array to label your outputs clearly based on the order you pushed them
    vector<string> labels = {"Inorder:   ", "Preorder:  ", "Postorder: "};
    
    // FIX 2: Correct inner loop condition and added spacing
    for (int i = 0; i < ans.size(); i++) {
        cout << labels[i]; // Print the label so you know which is which
        
        for(int j = 0; j < ans[i].size(); j++){ 
            cout << ans[i][j] << " "; // Added a space!
        }
        cout << endl;
    }

    // Clean up memory before exiting
    deleteTree(root);

    return 0;
}