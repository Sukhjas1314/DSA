#include<iostream>
#include<math.h>
using namespace std;
bool ispowerof2(int n){
    for(int i = 0 ; i <= 30 ; i++){
        int ans = pow(2,i);
        if(ans == n){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    if(ispowerof2(n)){
        cout << "True";
    }
    else{
        cout << "False";
    }
    cout << endl;
    return 0;
}
