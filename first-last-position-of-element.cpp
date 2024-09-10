#include<iostream>
using namespace std;
int firstOccurence(int arr[],int n,int target){
    int high = n - 1;
    int low = 0;
    int ans = -1;
    while(high >= low){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            ans = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
    }
    return ans;
}
int lastOccurence(int arr[],int n,int target){
    int high = n - 1;
    int low = 0;
    int ans = -1;
    while(high >= low){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            ans = mid;
            low = mid + 1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
    }
    return ans;
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
    cout << "Enter the target element : ";
    cin >> target;

    int first = firstOccurence(arr,n,target);
    int last = lastOccurence(arr,n,target);

    if(!first){
        cout << "The value doesn't exists in the array." << endl;
    }
    else{
        cout << "First occurence of " << target << " is at position : " << first << endl;
    }

    if(last){
        cout << "Last occurence of " << target << "  is at position : " << last << endl;
    }

    cout << "Total no. of occurences of " << target << " is : " << (last-first) + 1 << endl;
    
    cout << endl;
    return 0;
}