#include<iostream>
using namespace std;

// merging fn for both sorted temp arrays into a final sorted arr[]
void merge(int arr[],int l,int mid,int r){

    // size of the two temp arrays
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Temp arrays left array & right array which will be merged in the final arr[]
    int a[n1];
    int b[n2];

    // filling the elements in the two temp arrays
    for(int i = 0 ; i < n1 ; i++){
        a[i] = arr[l + i];
    }
    for(int j = 0 ; j < n2 ; j++){
        b[j] = arr[mid + 1 + j];
    }

    // Sorting algo
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while(i < n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < n2){
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[],int l,int r){

    if(l < r){
        int mid = l + (r - l) / 2;

        // sorting the first half of the arr[]
        mergeSort(arr,l,mid);
        // sorting the second half of the arr[]
        mergeSort(arr,mid + 1,r);

        // merging both sorted arrays
        merge(arr,l,mid,r);
    }
}

int main(){
    int arr[] = {6,3,9,5,2,8,7,1};
    mergeSort(arr,0,7);
    for(int i = 0 ; i < 8 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}