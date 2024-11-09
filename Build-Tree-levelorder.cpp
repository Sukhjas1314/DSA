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
void printLevelOrder(node* &root){
    if(root == NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n != NULL){
            cout << n->data << " ";
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        else if (!q.empty()){
            q.push(NULL);
            cout << endl;
        }
    }
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);
    root->right->left->left = new node(12);
    root->right->left->right = new node(13);
    root->right->right->left = new node(14);
    root->right->right->right = new node(15);
    
    printLevelOrder(root);
    cout << endl;
    return 0;
}