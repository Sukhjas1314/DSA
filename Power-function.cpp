#include<iostream>
using namespace std;
void power(int a,int b){
    int ans = 1;
    for(int i = 1 ; i <= b ; i++){
        ans = ans * a;
    }
    cout << a << "^" << b << " = " << ans << endl;
}
int main(){
    int a,b;
    cout << "Enter the base : ";
    cin >> a;
    cout << "Enter the power : ";
    cin >> b;

    power(a,b);
    cout << endl;
    return 0;
}