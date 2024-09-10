#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;

    cout << "Size of the vector : " << v.size() << endl;
    cout << "Capacity of the vector : " << v.capacity() << endl;

    v.push_back(1);
    cout << "Size of the vector : " << v.size() << endl;
    cout << "Capacity of the vector : " << v.capacity() << endl;
    v.push_back(2); 
    cout << "Size of the vector : " << v.size() << endl;
    cout << "Capacity of the vector : " << v.capacity() << endl;
    v.push_back(3); 
    cout << "Size of the vector : " << v.size() << endl;
    cout << "Capacity of the vector : " << v.capacity() << endl;
    v.push_back(4); 
    cout << "Size of the vector : " << v.size() << endl;
    cout << "Capacity of the vector : " << v.capacity() << endl;
    v.push_back(5); 
    cout << "Size of the vector : " << v.size() << endl;
    cout << "Capacity of the vector : " << v.capacity() << endl;
    v.push_back(6); 
    cout << "Size of the vector : " << v.size() << endl;
    cout << "Capacity of the vector : " << v.capacity() << endl;

    v.pop_back();
    v.pop_back();

    cout << "Size of the vector : " << v.size() << endl;
    cout << "Capacity of the vector : " << v.capacity() << endl;

    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    for(int element:v){
        cout << element << " ";
    }
    cout << endl;

    int i = 0;
    while(i < v.size()){
        cout << v[i++] << " ";
    }
    cout << endl;

    v.insert(v.begin() + 2 , 6);

    for(int ele:v){
        cout << ele << " ";
    }
    cout << endl;

    v.erase(v.end() - 2);

    for(int element:v){
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}