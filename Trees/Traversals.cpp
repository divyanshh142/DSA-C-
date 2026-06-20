#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to build a binary tree from preorder traversal
static int idx = -1;

Node* buildTree(vector<int>& preorder) {

    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(Node * root){

    if(root ==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(Node * root){

    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(Node * root){

    if(root == NULL){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

// Function to perform level-order traversal of the binary tree
void LevelorderTraversal(Node * root){

    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(q.size() > 0){

        Node * curr = q.front();
        q.pop();

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

int main() {

    vector<int> preorder = {1, 2, 1, 1, 3, 4, -1, -1, 5, -1, -1};


    Node* root = buildTree(preorder);
    cout << "Tree built successfully!" << endl;


    cout << "Preorder traversal: ";
    preorderTraversal(root);

    cout << "Inorder traversal: ";
    inorderTraversal(root);

    cout << "Postorder traversal: ";
    postorderTraversal(root);

    cout << "Level-order traversal: ";
    LevelorderTraversal(root);

    cout << endl;

    return 0;
}