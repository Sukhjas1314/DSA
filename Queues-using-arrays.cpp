#include<iostream>
using namespace std;
#define N 5
int queue[N];
int front = -1 , rear = -1;
void enqueue(int x){
    if(rear == (N - 1)){
        cout << "Queue is full" << endl;
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
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
        front++;
    }
}
void display(){
    if(front == -1 && rear == -1){
        cout << "Queue is empty" << endl;
    }
    else{
        for(int i = front ; i <= rear ; i++){
            cout << queue[i] << endl;
        }
    }
}
void peek(){
    if(front == -1 && rear == -1){
        cout << "Queue is empty" << endl; 
    }
    else{
        cout << queue[front] << endl;
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
void isFull(){
    if(rear == (N - 1)){
        cout << "Queue is full" << endl;
    }
    else{
        cout << "Queue is not full" << endl;
    }
}

int main(){
    int ch;
    do{
        cout << endl << "Choices are -:\n1 -> enqueue\n2 -> dequeue\n3 -> peek\n4 -> display\n5 -> isEmpty\n6 -> isFull" << endl << endl;
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