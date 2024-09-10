#include<iostream>
using namespace std;

void printarr(int arr[],int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOne(int arr[],int size){
    int i = 0 , j = size - 1;
    while(i < j){
        while(arr[i] == 0){
            i++;
        }
        while(arr[j] == 1){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
}
int main(){
    int arr[8] = {1,0,1,0,0,1,1,0};
    sortOne(arr,8);
    printarr(arr,8);
    return 0;
}