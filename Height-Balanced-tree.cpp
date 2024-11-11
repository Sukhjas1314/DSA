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
//  For T(n) = O(n^2)
// int height(node* &root){
//     if(root == NULL){
//         return 0;
//     }
//     int lh = height(root->left);
//     int rh = height(root->right);
//     return max(lh,rh) + 1;
// }
// bool isBalanced(node* &root){
//     if(root == NULL){
//         return true;
//     }
//     if(isBalanced(root->left) ==  false){
//         return false;
//     }
//     if(isBalanced(root->right) == false){
//         return false;
//     }
//     int lh = height(root->left);
//     int rh = height(root->right);
//     if(abs(lh - rh) <= 1){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

//  For T(n) = O(n)
bool isBalanced(node* &root,int* height){
    if(root == NULL){
        return true;
    }
    int lh = 0,rh = 0;
    if(isBalanced(root->left,&lh)){
        return false;
    }
    if(isBalanced(root->right,&rh)){
        return false;
    }

    *height = max(lh,rh) + 1;
    if(abs(lh - rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    // root->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->left->right = new node(7);

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);
    root2->right->left = new node(6);
    root2->right->right = new node(7);

    int height = 0;
    if(isBalanced(root1,&height) == true){
        cout << "This tree is height balanced tree." << endl;
    }
    else{
        cout << "This tree is not a height balanced tree." << endl;
    }

    if(isBalanced(root2,&height) == true){
        cout << "This tree is height balanced tree." << endl;
    }
    else{
        cout << "This tree is not a height balanced tree." << endl;
    }
    return 0;
}