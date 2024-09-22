#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

                    // Creation of array
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << endl;

                    // Display of array
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

                    // Insertion in the array
    int pos,value;
    cout << "Enter the position where you want to insert the element : ";
    cin >> pos;
    cout << "Enter the element you want to insert : ";
    cin >> value;
    for(int i = n ; i > pos ; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

                    // Deletion of element from the array
    int posd;
    cout << "Enter the position of the element you want to delete : ";
    cin >> posd;
    for(int i = 0 ; i < n ; i++){
        if(i == posd){
            for(int j = i ; j < n ; j++){
                arr[j] = arr[j + 1];
            }
            n--;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

                    // Linear Search
    int target;
    cout << "Enter the element you want to search : ";
    cin >> target;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == target){
            cout << "The index of the target element is : " << i << endl;
        }
    }
    cout << endl;
    return 0;
}