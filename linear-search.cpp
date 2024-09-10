#include<iostream>
using namespace std;
int search(int arr[],int n,int target){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout << "Enter size of the array : ";
    cin >> n;

    int arr[n],target;

    cout << "Enter the elements : " << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    cout << "The array is : ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    
    cout << "Enter value of target/element you want to search : ";
    cin >> target;

    int lsearch = search(arr,n,target);

    if(lsearch == -1){
        cout << "The target doesn't exists."; 
    }
    else { 
        cout << "The target exists at position : " << lsearch << endl;
    }
    cout << endl;
    return 0;
}