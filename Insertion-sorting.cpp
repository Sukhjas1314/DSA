#include<iostream>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i = 1 ; i < n ; i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0){
            if(arr[j] > temp){
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main(){
    int arr[6] = {5,2,8,4,9,3};
    insertionSort(arr,6);
    for(int i = 0 ; i < 6 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}