#include<iostream>
using namespace std;
int pivotIndex(int arr[],int n){
    int sum = 0;
    int leftsum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(leftsum == sum - leftsum - arr[i]){
            return i;
        }
        leftsum += arr[i];
    }
    return -1;
}
int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << endl;

    int pivot = pivotIndex(arr,n);

    if(pivot == -1){
        cout << "The pivot index doesn't exists." << endl;
    }
    else{
        cout << "The pivot index is : " << pivot << endl;
    }
    cout << endl;
    return 0;
}