#include <iostream>
#include <climits> 
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    int calculateDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }

    bool isBSTUtil(Node* root, int minValue, int maxValue) {
        if (root == nullptr) {
            return true;
        }

        if (root->data < minValue || root->data > maxValue) {
            return false;
        }

        return  isBSTUtil(root->left, minValue, root->data - 1) &&
                isBSTUtil(root->right, root->data + 1, maxValue);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    int depth() {
        return calculateDepth(root);
    }

    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    void postOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }

    // Declaration for getRoot function
    Node* getRoot() const {
        return root;
    }
};

int main() {
    BST bst;

    // Inserting nodes
    bst.insert(45);
    bst.insert(67);
    bst.insert(22);
    bst.insert(100);
    bst.insert(75);
    bst.insert(13);
    bst.insert(11);
    bst.insert(64);
    bst.insert(30);

    // Deleting nodes
    bst.remove(22);
    bst.remove(100);

    // Depth of the tree
    cout << "Depth of the tree: " << bst.depth() << endl;

    // Check if the tree is a Binary Search Tree
    cout << "Is the tree a Binary Search Tree? " << (bst.isBST() ? "Yes" : "No") << endl;

    // Post-order traversal
    cout << "Post-order traversal: ";
    bst.postOrderTraversal(bst.getRoot());
    cout << endl;

    return 0;
}
