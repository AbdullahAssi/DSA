#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};
class BST{
    public:
    TreeNode* root;

    BST(): root(nullptr){}

    TreeNode* insert(TreeNode* root, int key){
        if(root == nullptr){
            return new TreeNode(key);
        }
        else{
            if(key <root->val){
                root ->left = insert(root->left, key);
            }
            else{
                root ->right = insert(root->right, key);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root == nullptr){
            return root;
        }
        if(key< root-> val){
            root -> left = deleteNode(root->left, key);
        }
        else if (key >root->val){
            root ->  right = deleteNode(root->right, key);
        }else{
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else{
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
        }
    }

    void Preorder(TreeNode* root){
        if(root != nullptr){
            cout<<root->val<<" ";
            Preorder(root->left);
            Preorder(root->right);
        }
    }
};


int main(){
    BST bst;
    bst.root = bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 60);
    bst.insert(bst.root, 80);

    cout<<"Printing the tree ";
    bst.Preorder(bst.root);

    cout<<"\n Deleting the node ;";
    bst.root = bst.deleteNode(bst.root, 70);
    // bst.deleteNode(bst.root, 70);

    cout<<"Printing the tree after deleting 70 ";
    bst.Preorder(bst.root);



}