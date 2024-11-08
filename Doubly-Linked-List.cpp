#include<iostream>
using namespace std;
class node{
    public :
        int data;
        node *prev;
        node *next;

        node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};
void search(node* &head,int value){
    if(head == NULL){
        cout << "The linked list is empty" << endl;
        return;
    }
    node* temp = head;
    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Element not found." << endl;
    }
    else{
        cout << "Element found." << endl;
    }
}
void insertAtHead(node *&head,int val){
    node *p = new node(val);
    p->next = head;
    if(head != NULL){
        head->prev = p; 
    }
    head = p;
}
void insertAtTail(node *&head,int val){
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node *n = new node(val);
    node *temp = head;

    while(temp->next != NULL){
        temp = temp->next; 
    }
    temp->next = n;
    n->prev = temp;
}
void deletionAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
};                                                
void deletion(node* &head,int pos){

    if(pos == 1){
        deletionAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;

    while(temp != NULL && count != pos){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}
void display(node *&head){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << endl;
}
int main(){
    node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,7);
    display(head);
    insertAtHead(head,6);
    insertAtTail(head,9);
    display(head);
    deletion(head,4);
    deletion(head,2);
    display(head);
    search(head,3);
    search(head,10);
    return 0; 
}
