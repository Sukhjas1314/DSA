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
int main(){
    peek();
    cout << endl;

    push(3);
    peek();
    cout << endl;

    push(4);
    peek();
    pop();
    peek();
    cout << endl;

    push(5);
    peek();
    pop();
    cout << endl;

    display();
    cout << endl;
    return 0;
}