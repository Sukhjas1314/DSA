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
node* createBST(int preorder[],int* preorderIdx,int key,int min,int max,int n){
    if(*preorderIdx > n){
        return NULL;
    }
    node* root = NULL;
    if(key > min && key < max){
        root = new node(key);
        *preorderIdx += 1;

        if(*preorderIdx < n){
            root->left = createBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx < n){
            root->right = createBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
}
void preOrder(node* &root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    int preorder[] = {10,2,1,13,11};
    int n = 5;
    int preorderIdx = 0;

    node* root = createBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    preOrder(root);
    cout << endl;
    return 0;
}