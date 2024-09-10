#include<iostream>
using namespace std;
bool isprime(int a){
    for(int i = 2 ; i < a ; i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cout << "Enter any number : ";
    cin >> n;

    if(isprime(n) == 0){
        cout << n << " is not a prime number";
    }
    else{
        cout << n << " is a prime number";
    }
    cout << endl;
    return 0;
}