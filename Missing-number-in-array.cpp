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

int missingNo(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] != i + 1){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int arr[5] = {3,2,5,6,4};
    bubbleSort(arr,5);
    int missing = missingNo(arr,5);
    cout << "The missing number is : " << missing << endl;
    cout << endl;
    return 0;
}