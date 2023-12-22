#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* createNode(int data) {
        Node* newNode = new Node();
        if (newNode) {
            newNode->data = data;
            newNode->left = newNode->right = nullptr;
        }
        return newNode;
    }

    Node* insertNode(Node* root, int data) {
        if (root == nullptr) {
            root = createNode(data);
        }
        else if (data <= root->data) {
            root->left = insertNode(root->left, data);
        }
        else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) {
            return root;
        }
        else if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            }
            else if (root->left == nullptr) {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    void preOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    int calculateDepth(Node* root){
        if(root == nullptr){
            return 0;
        }
        else{
            int leftDepth = calculateDepth(root->left);
            int rightDepth = calculateDepth(root->right);

            if(leftDepth > rightDepth){
                return leftDepth + 1;
            }
            else{
                return rightDepth + 1;
            }
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertNode(root, data);
    }


    void remove(int data) {
        root = deleteNode(root, data);
    }

    int depth() {
        return calculateDepth(root);
    }
    
    void preOrder() {
        preOrderTraversal(root);
    }
};

int main() {
    BST bst;

    // Inserting nodes
    bst.insert(11);
    bst.insert(67);
    bst.insert(22);
    bst.insert(83);
    bst.insert(47);
    bst.insert(15);
    bst.insert(18);
    bst.insert(16);
    bst.insert(64);
    bst.insert(30);

    // Deleting nodes
    bst.remove(11);
    bst.remove(67);
    bst.remove(22);
    bst.remove(83);

    // Depth of the tree
    cout << "Depth of the tree: " << bst.depth() << endl;

    // Pre-order traversal
    cout << "Pre-order traversal: ";
    bst.preOrder();
    cout << endl;

    return 0;
}
