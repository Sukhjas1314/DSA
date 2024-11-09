#include<iostream>
#include<queue>
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
int calcHeight(node* root){
    if(root == NULL){
        return 0;
    }
    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);
    return max(lheight,rheight)+1;
}
int calcDiameter(node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    // root->left->left->left = new node(8);
    // root->left->left->right = new node(9);
    // root->left->right->left = new node(10);
    // root->left->right->right = new node(11);
    // root->right->left->left = new node(12);
    // root->right->left->right = new node(13);
    // root->right->right->left = new node(14);
    // root->right->right->right = new node(15);

    cout << calcDiameter(root) << endl;

    return 0;
}