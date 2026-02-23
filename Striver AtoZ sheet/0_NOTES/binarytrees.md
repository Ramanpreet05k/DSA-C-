# BINARY TREES

## Basics

#### Binary Tree define
- data is heirarchical data structure 
- a node can have a max of 2 children

- root : starting point of the binary tree on top level
- children : nodes attatch to any other node
- parent : node having children 
- leaf node : any node which has 0 child
- subtree : extracted part or portion of tree


### Binary Tree Types
1. Binary Tree
2. Binary Search Tree
3. N-array Tree
4. Full Binary Tree : all nodes must have 2 or 0 children
5. Complete Binary Tree : 
 - All levels must be completely filled except the last level
 - the last level has all nodes in left as possible
6. Perfect Binary Tree : all leaf nodes are at the same level , all non leaf nodes must have 2 children.
7. Balanced Binary Tree : height difference between left and right subtree at any noode must be at max 1.
8. Degenerate Binary Tree : every node has a single child associated with it.

### binary Tree Representation in c++

Struct Node {
    int data;
    Node* left,right;
    Node(int _data){
        data = _data;
        left = right = null;
    }
}

main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
}


### Binary Tree Representation in java

class Node {
    int data;
    Node left,right;

    Node(int _data){
        data = _data
        left= right = Null
    }
}
 main(){
    nODE ROOT = NEW node(1);
    root.left = new Node(2);
    root.right = new Node(3);
 }


 ### Traversal Techniques 

#### **Inorder Traversal**
- left - root - right
- traversal is done in this way

#### **Preorder Traversal**
- root - left - right
- traversal is done in this way

#### **Postorder Traversal**
- left - right - root
- traversal is done in this way


 ### Basics of bINARY tREE IN C++

