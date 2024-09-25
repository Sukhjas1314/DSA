#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *link;
};
struct node *head;
void createCLL(){
    struct node *newnode = new node();
    struct node *temp;
    head = 0;
    temp = head;
    cout << "Enter the data : ";
    cin >> newnode->data;

    newnode->link = 0;
    if(head == 0){
        head = newnode;
        temp = newnode;
    }
    else{
        temp->link = newnode;
        temp = newnode;
    }
    temp->link = head;
}
void display(){
    struct node *temp;
    if(head == 0){
        cout << "Linked list is empty" << endl;
    }
    else{
        temp = head;
        while(temp->link != head){
            cout << temp->data << endl;
            temp = temp->link;
        }
        cout << temp->data << endl;
    }
}
