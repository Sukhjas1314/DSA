#include<iostream>
using namespace std;
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else if((rear + 1) % N == front){
        cout << "Queue is full" << endl;
    }
    else{
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void dequeue(){
    if(front == -1 && rear == -1){
        cout << "Queue is empty" << endl;
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        cout << queue[front] << endl;
        front = (front + 1) % N;
    }
}
void isFull(){
    if((rear + 1) % N == front){
        cout << "Queue is full" << endl;
    }
    else{
        cout << "Queue is not full" << endl;
    }
}
void isEmpty(){
    if(front == -1 && rear == -1){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }
}
void display(){
    if(front == -1 && rear == -1){
        cout << "Queue is empty" << endl;
    }
    else{
        while(front != rear){
            cout << queue[front] << endl;
            front = (front + 1) % N;
        }
        cout << queue[front] << endl;
    }
}
void peek(){
    if(front == -1 && rear == -1){
        cout  << "Queue is empty" << endl;
    }
    else{
        cout << queue[front] << endl;
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