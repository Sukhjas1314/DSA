#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << endl;
    int *b = new int[n];
    int pos = 0;
    bool isdistinct;

    for(int i = 0 ; i < n ; i++){
        isdistinct = true;
        for(int j = 0 ; j < i ; j++){
            if(arr[i] == arr[j]){
                isdistinct = false;
                break;
            }
        }
        if(isdistinct){
            b[pos] = arr[i];
            pos++;
        }
    }
    for(int i = 0 ; i < pos ; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}