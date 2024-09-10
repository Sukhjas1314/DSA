#include<iostream>
using namespace std;
int fibonacci(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cout << "Enter value of n : ";
    cin >> n;

    cout << "The " << n << "th fibonacci number is : " << fibonacci(n) << endl;

    cout << endl;
    return 0;
}