#include<iostream>
using namespace std;
int findUnique(int arr[],int n){
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
int main(){
    int n;
    cout << "Enter the size : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int unique = findUnique(arr,n);
    cout << "The unique number is : " << unique << endl;

    cout << endl;
    return 0;
}