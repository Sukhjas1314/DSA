#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        int min = i;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
}
int main(){
    int arr[5] = {5,2,8,4,9};
    selectionSort(arr,5);

    for(int i = 0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}