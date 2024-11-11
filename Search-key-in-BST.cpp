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
node* searchBST(node* &root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return searchBST(root->left,key);
    }
    return searchBST(root->right,key);
}
int main(){
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    int key = 7;
    if(searchBST(root,key) == NULL){
        cout << key << " doesn't exists in the Binary Tree" << endl;
    }
    else{
        cout << key << " exists in the Binary Tree" << endl;
    }
    return 0;
}