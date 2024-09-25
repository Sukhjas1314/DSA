#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *link;
};
struct node *head = 0;
int count1 = 0;
void insertatBegining(int x){
    struct node *newnode = new node();
    newnode->data = x;
    newnode->link = head;
    head = newnode;
}
void insertatend(int x){
    struct node *newnode = new node();
    newnode->data = x;
    newnode->link = 0;

    if(head == 0){
        head = newnode;
    }
    else{
        struct node *temp;
        temp = head;
        while(temp->link != 0){
            temp = temp->link;
        }
        temp->link = newnode;
    }
}
void insertatposition(int x,int pos){
    struct node *newnode = new node();
    newnode->data = x;

    if(pos == 1){
        newnode->link = head;
        head = newnode;
    }
    struct node *temp;
    temp = head;
    for(int i = 0 ; i < pos - 1 ; i++){
        if(temp == 0){
            delete newnode;
        }
        temp = temp->link;
    }

    if(temp != 0){
        newnode->link = temp->link;
        temp->link = newnode;
    }
    else{
        delete newnode;
    }
}
void deletefromstart(){
    if(head == 0){
        cout << "Linked list is empty" << endl;
    }
    struct node *temp;
    temp = head;
    head = head->link;
    cout << temp->data << endl;
    delete temp;
}
void deletefromend(){
    if(head == 0){
        cout << "Linked list is empty" << endl;
    }
    if(head->link == 0){
        cout << head->data << endl;
        delete head;
        head = 0;
    }
    struct node *temp;
    temp = head;
    struct node *prev;
    prev = 0;

    while(temp->link != 0){
        prev = temp;
        temp = temp->link; 
    }
    prev->link = 0;
    cout << temp->data << endl;
    delete temp;
}
void deletefromposition(){
    struct node *temp;
    struct node *nextnode;
    int pos , i = 1;
    cout << "Enter the position : ";
    cin >> pos;
    temp = head;
    while(i < pos - 1){
        temp = temp->link;
        i++;
    }
    nextnode = temp->link;
    temp->link = nextnode->link;
    delete nextnode;
}
void display(){
    struct node *temp;
    temp = head;
    while(temp != 0){
        cout << temp->data << endl;
        temp = temp->link;
        count1++;
    }
    cout << endl << "Length of the linked list is : " << count1 << endl;
}

int main(){
    int ch;
    do{
        cout << endl << "Choices are -:\n1 -> Insert at beginning\n2 -> Insert at end\n3 -> Insert at any position\n4 -> Delete from beginning\n5 -> Delete from end\n6 -> Delete from any position\n7 -> Display" << endl << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch(ch){
            case 1 :
                int x;
                cout << "Enter the value you want to insert in the linked list : ";
                cin >> x;
                insertatBegining(x);
                break;
            case 2 :
                int a;
                cout << "Enter the value you want to insert in the linked list : ";
                cin >> a;
                insertatend(a);
                break;
            case 3 : 
                int b,pos;
                cout << "Enter the value you want to insert in the linked list : ";
                cin >> b;
                cout << "Enter the position : ";
                cin >> pos;
                insertatposition(b,pos);
                break;
            case 4 :
                deletefromstart();
                break;
            case 5 :
                deletefromend();
                break;
            case 6 :
                deletefromposition();
                break;
            case 7 :
                display();
                break;
            default : 
                cout << "Your choice is invalid" << endl;
        }
    }
    while(ch != 0);
    cout << endl;
    return 0;
}