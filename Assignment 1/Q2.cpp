#include<iostream>
using namespace std;
void merge(int arr[],int s,int m,int e){
    // making temporary divided arrays
    int n1 = m - s + 1;
    int n2 = e - m;
    int a[n1],b[n2];

    // copying the elements in the new divided arrays
    for (int i = 0 ; i < n1 ; i++){
        a[i] = arr[s + i];
    }
    for (int i = 0 ; i < n2 ; i++){
        b[i] = arr[m + 1 + i];
    }

    int i = 0,j = 0,k = s;

    // copying back the divided arrays into 1 single array(merged array)
    while (i < n1 && j < n2){
        if(a[i] <= b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while (i < n1){
        arr[k++] = a[i++];
    }
    while (j < n2){
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[],int s,int e){
    if (e > s){
        int mid = s + (e - s) / 2;

        // Sort the divided arrays
        mergeSort(arr,s,mid);
        mergeSort(arr,mid + 1,e);

        // Merge the sorted arrays
        merge(arr,s,mid,e);
    }
}

int main(){
    int arr[] = {11,12,13,6,5,7};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for (int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}