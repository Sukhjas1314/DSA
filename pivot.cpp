#include<iostream>
using namespace std;
int getpivot(int arr[],int n){
    int s = 0; 
    int e = n - 1;
    while(s < e){
        int mid = s + (e - s) / 2;
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return s;
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
    
    cout << "Pivot is : " << getpivot(arr,n) << endl;
    cout << endl;
    return 0;
}