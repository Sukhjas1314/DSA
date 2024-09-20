#include<iostream>
using namespace std;
bool isPossible(int arr[],int n,int m,int mid){
    int StCount = 1;
    int pageSum = 0;
    for(int i = 0 ; i < n ; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            StCount++;
            if(StCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int findPages(int arr[],int n,int m){
    if(m > n){
        return -1;
    }
    int s = 0;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n,m;
    cout << "Enter the number of books : ";
    cin >> n;

    cout << "Enter the number of students : ";
    cin >> m;

    int arr[n];
    cout << "Enter the number of pages in the array : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << endl;

    cout << "The minimum number of pages a student gets : " << findPages(arr,n,m);
    cout << endl;
    return 0;
}