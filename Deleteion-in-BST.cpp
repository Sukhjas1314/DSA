#include<iostream>
using namespace std;
class node{
    public :
        int data;
        node* left;
        node* right;

        node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};
node* inorderSuccessor(node* root){
    node* curr = root;
    if(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
node* deleteinBST(node* &root,int key){
    if(root->data > key){
        root->left = deleteinBST(root->left,key);
    }
    else if(root->data < key){
        root->right = deleteinBST(root->right,key);
    }
    else{
        if(root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteinBST(root->right,temp->data);
    }
    return root;
}
void inorder(node* &root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    cout << "Before Deletion : "; 
    inorder(root);
    cout << endl;
    root = deleteinBST(root,2);
    cout << "After Deletion : "; 
    inorder(root);
    cout << endl;
    return 0;
}