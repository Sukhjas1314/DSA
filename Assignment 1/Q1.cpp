#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int target){
    int s = 0;
    int e = n - 1;
    while (e > s){
        int mid = s + (e - s) / 2;
        if (arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return s;
}
int main(){
    int arr[] = {2,5,8,12,16,23,38,56,72,91};
    int n = sizeof(arr)/sizeof(int);
    int target = 23;
    int idx = binarySearch(arr,n,target);
    cout << "The index of the the target number i.e " << target << " is : " << idx << endl;
    return 0;
}