#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i = 1 ; i < n ; i++){
        bool swapped = false;
        for(int j = 0 ; j < n - i ; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j],arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}
int main(){
    int arr[6] = {5,2,8,4,9,3};
    bubbleSort(arr,6);
    for(int i = 0 ; i < 6 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}