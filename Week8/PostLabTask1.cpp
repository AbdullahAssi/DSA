#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = _insert(root, key);
    }

    TreeNode* _insert(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        }
        if (key < root->key) {
            root->left = _insert(root->left, key);
        } else if (key > root->key) {
            root->right = _insert(root->right, key);
        }
        return root;
    }

    void deleteNode(int key) {
        root = _delete(root, key);
    }

    TreeNode* _delete(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->key) {
            root->left = _delete(root->left, key);
        } else if (key > root->key) {
            root->right = _delete(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            root->key = getMinValue(root->right);
            root->right = _delete(root->right, root->key);
        }
        return root;
    }

    int getMinValue(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root->key;
    }

    int depth() {
        return _depth(root);
    }

    int _depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = _depth(root->left);
        int rightDepth = _depth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

    void preOrderTraversal(vector<int>& result) {
        _preOrderTraversal(root, result);
    }

    void _preOrderTraversal(TreeNode* root, vector<int>& result) {
        if (root != nullptr) {
            result.push_back(root->key);
            _preOrderTraversal(root->left, result);
            _preOrderTraversal(root->right, result);
        }
    }
};

int main() {
    BST bst;
    vector<int> numbers = {11, 67, 22, 83, 47, 15, 18, 16, 64, 30};

    // Insert numbers into the BST
    for (int num : numbers) {
        bst.insert(num);
    }

    // Draw and Identify depth of the tree
    int depth = bst.depth();
    cout << "Depth of the BST: " << depth << endl;

    // Traverse BST using pre-order traversal
    vector<int> traversalResult;
    bst.preOrderTraversal(traversalResult);
    cout << "Pre-order Traversal: ";
    for (int num : traversalResult) {
        cout << num << " ";
    }
    cout << endl;

    // Delete 4 nodes
    vector<int> nodesToDelete = {22, 47, 64, 18};
    for (int node : nodesToDelete) {
        bst.deleteNode(node);
    }

    // Draw and Identify depth of the tree after deletion
    int depthAfterDeletion = bst.depth();
    cout << "Depth of the BST after deletion: " << depthAfterDeletion << endl;

    // Traverse BST using pre-order traversal after deletion
    vector<int> traversalResultAfterDeletion;
    bst.preOrderTraversal(traversalResultAfterDeletion);
    cout << "Pre-order Traversal after deletion: ";
    for (int num : traversalResultAfterDeletion) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
