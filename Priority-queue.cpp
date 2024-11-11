#include<iostream>
#include<queue>
using namespace std;
int main(){
    // Max heap
    priority_queue<int> pq;
    pq.push(3);
    pq.push(2);
    pq.push(4);
    pq.push(5);
    pq.push(1);

    cout << "Size of the priority_queue : " << pq.size() << endl;

    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Size of the priority_queue : " << pq.size() << endl;


    // Min heap
    priority_queue<int,vector<int>,greater<int>  > minHeap;

    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(4);
    minHeap.push(5);
    minHeap.push(1);

    cout << "Size of the priority_queue : " << minHeap.size() << endl;

    cout << "Top element : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Size of the priority_queue : " << minHeap.size() << endl;

    return 0;
}