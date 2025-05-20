#include<iostream>
using namespace std;

void minPlatforms(int arr[],int dep[],int n){
    sort(arr,arr + n);
    sort(dep,dep + n);

    int platform_needed = 1;
    int max_platform = 1;
    int i = 1,j = 0;

    while(i < n && j < n){
        if (arr[i] <= dep[j]){
            platform_needed++;
            i++;
        }
        else{
            platform_needed--;
            j++;
        }
        max_platform = max(max_platform,platform_needed);
    }
    cout << "The minimum number of platforms required for " << n << " trains : " << max_platform << endl;
}

int main(){
    int arr[] = {900,940,950,1100,1500,1800};
    int dep[] = {910,1200,1120,1130,1900,2000};
    int n = sizeof(arr)/sizeof(int);

    cout << endl;
    minPlatforms(arr,dep,n);
    cout << endl;
    
    return 0;
}