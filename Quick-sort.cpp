#include<iostream>
using namespace std;

// Swapping fn
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// For finding the correct position/index of the pivot element
int partition(int arr[],int l,int r){
    // pivot element is the last element in the array
    int pivot = arr[r];

    // take one pointer
    int i = l - 1;
    
    // start a loop in which the array before pointer i would be less than pivot and b/w i & j ones will be greater than pivot  
    for(int j = l ; j < r ; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i + 1,r);

    // returning the index
    return i+1;
}

void quickSort(int arr[],int l,int r){
    if(l < r){

        // storing correct index of pivot
        int pi = partition(arr,l,r);

        // sorting elements smaller than the pivot element
        quickSort(arr,l,pi - 1);

        // sorting elements greater than pivot element
        quickSort(arr,pi,r);
    }
}

int main(){
    int arr[] = {6,3,9,5,2,8,7};
    quickSort(arr,0,6);
    for(int i = 0 ; i < 7 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}