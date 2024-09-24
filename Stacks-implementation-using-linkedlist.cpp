#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *link;
};
struct node *top = 0;
void push(int x){
    struct node *newnode = new node();
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}
void display(){
    struct node *temp;
    temp = top;
    if(top == 0){
        cout << "The stack is empty" << endl;
    }
    else{
        while(temp != 0){
            cout << temp->data << endl;
            temp = temp->link;
        }
    }
}
void peek(){
    if(top == 0){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << top->data << endl;
    }
}
void pop(){
    struct node *temp;
    temp = top;
    if(top == 0){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << temp->data << endl;
        top = temp->link;
        delete temp;
    }
}

int main(){
    int ch;
    do{
        cout << "Choices are -:\n1 -> push\n2 -> pop\n3 -> peek\n4 -> display" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch(ch){
            case 1 :
                int x;
                cout << "Enter the value you want to insert in the stack : ";
                cin >> x;
                push(x);
                break;
            case 2 :
                pop();
                break;
            case 3 : 
                peek();
                break;
            case 4 :
                display();
                break;
            default : 
                cout << "Your choice is invalid" << endl;
        }
    }
    while(ch != 0);
    return 0;
}