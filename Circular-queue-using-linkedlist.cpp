#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *link;
};
struct node *front = 0;
struct node *rear = 0;

void enqueue(int x){
    struct node *newnode = new node();
    newnode->data = x;
    newnode->link = 0;

    if(rear == 0){
        front = newnode;
        rear = newnode;
        rear->link = front;
    }
    else{
        rear->link = newnode;
        rear = newnode;
        rear->link = front;
    }
}
void dequeue(){
    struct node *temp;
    temp = front;

    if(front == 0 && rear == 0){
        cout << "Queue is empty" << endl;
    }
    else if(front == rear){
        cout << front->data << endl;
        delete front;
        front = 0;
        rear = 0;
    }
    else{
        cout << front->data << endl;
        front = front->link;
        rear->link = front;
        delete temp;
    }
}
void peek(){
    if(front == 0 && rear == 0){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << front->data << endl;
    }
}
void display(){
    struct node *temp;
    temp = front;

    if(front == 0 && rear == 0){
        cout << "Queue is empty" << endl;
    }
    else{
         while(temp->link != front){
            cout << temp->data << endl;
            temp = temp->link;
         }
         cout << temp->data << endl;
    }
}
void isEmpty(){
    if(front == 0){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }
}
void isFull(){
    if(front > rear){
        cout << "Queue is full" << endl;
    }
    else{
        cout << "Queue is not full" << endl;
    }
}
int main(){
    int ch;
    do{
        cout << endl << "Choices are -:\n1 -> Enqueue\n2 -> Dequeue\n3 -> Peek\n4 -> Display\n5 -> IsEmpty\n6 -> IsFull" << endl << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch(ch){
            case 1 :
                int x;
                cout << "Enter the value you want to insert in the queue : ";
                cin >> x;
                enqueue(x);
                break;
            case 2 :
                dequeue();
                break;
            case 3 : 
                peek();
                break;
            case 4 :
                display();
                break;
            case 5 :
                isEmpty();
                break;
            case 6 :
                isFull();
                break;
            default : 
                cout << "Your choice is invalid" << endl;
        }
    }
    while(ch != 0);
    cout << endl;
    return 0;
}