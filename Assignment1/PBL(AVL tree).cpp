#include <iostream>
using namespace std;

// Node structure for the tree
struct Node {
    int key;
    Node* left, *right;
    int height; // For AVL Tree

    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    // Function to perform inorder traversal
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    // Function to perform preorder traversal
    void preorder(Node* node) {
        if (node) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Function to perform postorder traversal
    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << " ";
        }
    }

    // Function to insert a key into BST
    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        return node;
    }

    // Function to remove a key from BST
    Node* remove(Node* node, int key) {
        if (!node)
            return node;

        if (key < node->key)
            node->left = remove(node->left, key);
        else if (key > node->key)
            node->right = remove(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
        return node;
    }

    // Function to find the node with the minimum value
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }
};

class AVLTree : public BST {
public:
    // Function to get the height of a node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Function to update the height of a node
    void updateHeight(Node* node) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    // Function to get the balance factor of a node
    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Function to perform left rotation
    Node* leftRotate(Node* z) {
        Node* y = z->right;
        Node* T2 = y->left;

        y->left = z;
        z->right = T2;

        updateHeight(z);
        updateHeight(y);

        return y;
    }

    // Function to perform right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Function to balance the tree
    Node* balance(Node* node) {
        if (!node)
            return node;

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            // Left-Right Case
            if (balanceFactor(node->left) < 0)
                node->left = leftRotate(node->left);
            // Left-Left Case
            return rightRotate(node);
        }
        // Right Heavy
        if (balance < -1) {
            // Right-Left Case
            if (balanceFactor(node->right) > 0)
                node->right = rightRotate(node->right);
            // Right-Right Case
            return leftRotate(node);
        }

        return node;
    }

    // Function to insert a key into AVL Tree
    Node* insert(Node* node, int key) {
        node = BST::insert(node, key);
        return balance(node);
    }

    // Function to remove a key from AVL Tree
    Node* remove(Node* node, int key) {
        node = BST::remove(node, key);
        return balance(node);
    }
};

int main() {
    AVLTree avlTree;
    avlTree.root = avlTree.insert(avlTree.root, 50);
    avlTree.root = avlTree.insert(avlTree.root, 30);
    avlTree.root = avlTree.insert(avlTree.root, 20);
    avlTree.root = avlTree.insert(avlTree.root, 15);
    avlTree.root = avlTree.insert(avlTree.root, 25);
    avlTree.root = avlTree.insert(avlTree.root, 35);
    avlTree.root = avlTree.insert(avlTree.root, 40);
    avlTree.root = avlTree.insert(avlTree.root, 70);
    avlTree.root = avlTree.insert(avlTree.root, 60);
    avlTree.root = avlTree.insert(avlTree.root, 80);
    avlTree.root = avlTree.insert(avlTree.root, 55);
    avlTree.root = avlTree.insert(avlTree.root, 10);

    cout << "AVL Tree Inorder: ";
    avlTree.inorder(avlTree.root);
    cout << endl;

    cout << "AVL Tree Preorder: ";
    avlTree.preorder(avlTree.root);
    cout << endl;

    cout << "AVL Tree Postorder: ";
    avlTree.postorder(avlTree.root);
    cout << endl;

    avlTree.root = avlTree.remove(avlTree.root, 50);

    cout << "After removing 50:" << endl;

    cout << "After balancing BST : ";
    avlTree.inorder(avlTree.root);
    cout << endl;

    return 0;
}
