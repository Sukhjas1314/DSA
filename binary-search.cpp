#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int target){
    int high = n - 1;
    int low = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            return mid; 
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
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

    int target;
    cout << "Enter the element you want to search : ";
    cin >> target;

    int binsearch = binarySearch(arr,n,target);

    if(binsearch == -1){
        cout << "The element you want to search doesn't exist in the array.";
    }
    else{
        cout << "The element you want to search exists in the array at position : " << binsearch << endl;
    }
    cout << endl;
    return 0;
}