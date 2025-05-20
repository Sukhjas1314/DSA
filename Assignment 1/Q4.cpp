#include<iostream>
using namespace std;
void sumofSubarray(int arr[],int n){
    int tsum = arr[0];
    int currentmax = arr[0];
    int start = 0,end = 0,tempstart = 0;

    for (int i = 0 ; i < n ; i++){
        if (arr[i] > currentmax + arr[i]){
            currentmax = arr[i];
            tempstart = i;
        }
        else{
            currentmax += arr[i];
        }

        if (currentmax > tsum){
            tsum = currentmax;
            start = tempstart;
            end = i;
        }
    }

    cout << "The subarray with largest sum : " << endl;
    for (int i = start ; i <= end ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The sum of this subarray is : " << tsum << endl;
}
int main(){
    int arr[] = {-2,-5,6,-2,-3,1,5,-6};
    int n = sizeof(arr)/sizeof(int);
    sumofSubarray(arr,n);
    return 0;
}