#include<iostream>
using namespace std;
void swapAlternate(int arr[],int n){
    for(int i = 0 ; i < n ; i+=2){
        if(i + 1 < n){
            swap(arr[i],arr[i+1]);
        }
    }
}
void printarr(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {5,7,3,8,5,9,4,2};
    int brr[] = {4,2,5,98,34,21,54};

    swapAlternate(arr,8);
    printarr(arr,8);

    swapAlternate(brr,7);
    printarr(brr,7);

    cout << endl;
    return 0;
}