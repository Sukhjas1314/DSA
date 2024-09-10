#include<iostream>
using namespace std;
int peakElement(int arr[],int n){
    int s = 0;
    int e = n - 1;
    while(s < e){
        int mid = s + (e  - s) / 2;
        if(arr[mid] < arr[mid + 1]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return s;
}
int main(){
    int arr[6] = {1, 3, 8, 12, 4, 2};

    int peak = peakElement(arr,6);

    cout << "The index of the peak element is : " << peak << endl;
    
    cout << endl;
    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to find the peak element in a mountain array using binary search
// int findPeakElement(vector<int>& nums) {
//     int left = 0, right = nums.size() - 1;

//     while (left < right) {
//         int mid = left + (right - left) / 2;

//         // Check if the middle element is part of the increasing slope
//         if (nums[mid] < nums[mid + 1]) {
//             // Peak lies to the right side
//             left = mid + 1;
//         } else {
//             // Peak lies to the left side or mid is the peak
//             right = mid;
//         }
//     }
//     // When left == right, we have found the peak element
//     return left; // This returns the index of the peak element
// }

// int main() {
//     // Example mountain array
//     vector<int> mountainArray(4);
//     cout << "Enter the elements : ";
//     for(int i = 0 ; i < 4 ; i++){
//         cin >> mountainArray[i];
//     }

//     // Finding the peak element index
//     int peakIndex = findPeakElement(mountainArray);

//     // Display the peak element and its index
//     cout << "Peak element is " << mountainArray[peakIndex] << " at index " << peakIndex << endl;

//     return 0;
// }
