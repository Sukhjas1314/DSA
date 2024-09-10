#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v(6);

    cout << "Enter the elements  : ";
    for(int i = 0 ; i < 6 ; i++){
        cin >> v[i];
    }
    cout << endl;

    int x;
    cout << "Enter x : ";
    cin >> x;

    int occurence = -1;

    // Last occurence if start from beginning
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] == x){
            occurence = i;
        }
    }
    cout << "The index of the last occurence is : " << occurence << endl;

    // First occurence if start from end
    for(int i = v.size() - 1 ; i >= 0 ; i--){
        if(v[i] == x){
            occurence = i;
            break;
        }
    }
    cout << "The index of the last occurence is : " << occurence << endl;

    cout << endl;
    return 0;
}