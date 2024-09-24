#include<iostream>
using namespace std;
#define N 5
int stack[N];
int top = -1;
void push(int x){
    if(top == N-1){
        cout << "Overflow" << endl;
    }
    else{
        top++;
        stack[top] = x;
    }
}
void pop(){
    int item;
    if(top == -1){
        cout << "Underflow" << endl;
    }
    else{
        item = stack[top];
        top--;
        cout << item << endl;
    }
}
void peek(){
    if(top == -1){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << stack[top] << endl;
    }
}
void display(){
    for(int i = top ; i >= 0 ; i--){
        cout << stack[i] << endl;
    }
}
void isEmpty(){
    if(top <= -1){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << "The stack is not empty" << endl;
    }
}
void isFull(){
    if(top >= (N-1)){
        cout << "The stack is full" << endl;
    }
    else{
        cout << "The stack is not full" << endl;
    }
}
int main(){
    int ch;
    do{
        cout << "Choices are -:\n1 -> push\n2 -> pop\n3 -> peek\n4 -> display\n5 -> isEmpty\n6 -> isFull" << endl;
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
    return 0;
}