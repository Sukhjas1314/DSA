#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *link;
};
struct node *tail;
int count1 = 0;
int getlength(){
    struct node *temp;
    temp = tail;
    while(temp != 0){
        temp = temp->link;
        count1++;
    }
    return count1;
}
void insertatBegining(){
    struct node *newnode = new node();
    cout << "Enter the data : ";
    cin >> newnode->data;
    newnode->link = 0;
    if(tail == 0){
        tail = newnode;
        tail->link = newnode;
    }
    else{
        newnode->link = tail->link;
        tail->link = newnode;
    }
    cout << tail->link->data << endl;
}
void insertatend(){
    struct node *newnode = new node();
    cout << "Enter the data : ";
    cin >> newnode->data;
    newnode->link = 0;
    if(tail == 0){
        tail = newnode;
        tail->link = newnode;
    }
    else{
        newnode->link = tail->link;
        tail->link = newnode;
        tail = newnode;
    }
}
void insertatposition(){
    struct node *newnode = new node();
    struct node *temp;
    int pos , i = 1 , l;
    cout << "Enter the position : ";
    cin >> pos;

    l = getlength();
    if(pos < 0 || pos > l){
        cout << "Invalid position" << endl;
    }
    else if(pos == 1){
        insertatBegining();
    }
    else{
        cout << "Enter the data : ";
        cin >> newnode->data;   
        newnode->link = 0;
        temp = tail->link;
        while(i < pos-1){
            temp = temp->link;
            i++;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
}
void deletefromstart(){
    struct node *temp;
    temp = tail->link;
    if(tail == 0){
        cout << "Linked list is empty" << endl;
    }
    else if(temp->link == temp){
        tail = 0;
        delete temp;
    }
    else{
        tail->link = temp->link;
        delete temp;
    }
}
void deletefromend(){
    struct node *curr , *prev;
    curr = tail->link;

    if(tail == 0){
        cout << "List is empty" << endl;
    }
    else if(curr->link == curr){
        tail = 0;
        delete curr;
    }
    else{
        while(curr->link == tail->link){
            prev = curr;
            curr = curr->link;
        }
        prev->link = tail->link;
        tail = prev;
        delete curr;
    }
}
void deletefromposition(){
    struct node *curr , *next;
    int pos , l , i = 1;
    curr = tail->link;
    cout << "Enter the length : ";
    cin >> pos;
    l = getlength();
    if(pos < 0 || pos > l){
        cout << "Position is invalid" << endl;
    }
    else if(pos == 1){
        deletefromstart();
    }
    else{
        while(i < pos - 1){
            curr = curr->link;
            i++;
        }
        next = curr->link;
        curr->link = next->link;
        delete next;
    }
}
int main(){
    return 0;
}