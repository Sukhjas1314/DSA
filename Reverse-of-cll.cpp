#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *link;
};
struct node *tail;
void reverse(){
    struct node *prev , *curr , *next;
    curr = tail->link;
    next = curr->link;
    if(tail == 0){
        cout << "List is empty" << endl;
    }
    while(curr != tail){
        prev = curr;
        curr = next;
        next = curr->link;
        curr->link = prev;
    }
    next->link = tail;
    tail = next;
}
int main(){
    return 0;
}