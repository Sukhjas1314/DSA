#include<iostream>
using namespace std;
void reverse(int arr[],int n){
    int start = 0;
    int end = n - 1;

    while(start <= end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void printarr(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int brr[] = {3,11,6,78,-23,76};

    reverse(arr,7);
    reverse(brr,6);

    printarr(arr,7);
    printarr(brr,6);
    cout << endl;
    return 0;
}