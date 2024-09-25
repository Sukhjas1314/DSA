#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *link;
};
struct node *head;
void reverse(){
    struct node *prev , *curr , *next;
    prev = 0;
    curr = head;
    next = head;

    while(next != 0){
        next = next->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}