#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans;
    int n;
    cout << "Enter the size of the array 1 : ";
    cin >> n;

    int arr[n];
    cout << "Enter the element in the array 1 : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << endl;

    int m;
    cout << "Enter the size of the array 2: ";
    cin >> m;

    int arr2[m];
    cout << "Enter the element in the array 2 : ";
    for(int j = 0 ; j < m ; j++){
        cin >> arr2[j];
    }
    cout << endl;

    for(int i = 0 ; i < n ; i++){
        int element = arr[i];
        for(int j = 0 ; j < m ; j++){
            if(element == arr2[j]){
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }

    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}