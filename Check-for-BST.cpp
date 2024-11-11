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
// T(n) = O(n)
bool checkBST(node* root,node* min = NULL,node* max = NULL){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }
    bool leftValid = checkBST(root->left,min,root);
    bool rightValid = checkBST(root->right,root,max);
    return leftValid and rightValid;
}
int main(){
    // node* root = new node(4);
    // root->left = new node(2);
    // root->right = new node(5);
    // root->left->left = new node(1);
    // root->left->right = new node(3);
    // root->right->right = new node(6);

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    if(checkBST(root) == true){
        cout << "It is BST" << endl;
    }
    else{
        cout << "It is not a BST" << endl;
    }
    return 0;
}