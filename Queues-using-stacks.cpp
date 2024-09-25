#include<iostream>
using namespace std;
#define N 5
int S1[N],S2[N];
int top1 = -1,top2 = -1;
int count1 = 0;
void push1(int data){
    if(top1 == (N - 1)){
        cout << "Queue is full" << endl;
    }
    else{
        top1++;
        S1[top1] = data;
    }
}
void enqueue(int x){
    push1(x);
    count1++;
}
int pop1(){
    return S1[top1--];
}
void push2(int data){
    if(top2 == (N - 1)){
        cout << "Queue is full" << endl;
    }
    else{
        top2++;
        S2[top2] = data;
    }
}
int pop2(){
    return S2[top2--];
}
void dequeue(){
    int a,b;
    if(top1 == -1 && top2 == -1){
        cout << "Queue is empty" << endl;
    }
    else{
        for(int i = 0 ; i < count1 ; i++){
            push2(pop1());
        }
        int b = pop2();
        cout << b << endl;
        count1--;
        for(int i = 0 ; i < count1 ; i++){
            a = pop2();
            push1(a);
        }
    }
}
void display(){
    if(top1 == -1){
        cout << "Queue is empty" << endl;
    }
    else{
        for(int i = 0 ; i <= top1 ; i++){
            cout << S1[i] << endl;
        }
    }
}
int main(){
    int ch;
    do{
        cout << endl << "Choices are -:\n1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n" << endl << endl;
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