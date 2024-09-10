#include<iostream>
using namespace std;
int factorial(int a){
    int fact = 1;
    for(int i = 1 ; i <= a ; i++){
        fact = fact * i;
    }
    return fact;
}
void ncr(int n,int r){
    int nfact = factorial(n);
    int rfact = factorial(r);
    int nrfact = factorial(n-r);
    cout << nfact << endl;
    cout << rfact << endl;
    cout << nrfact << endl;
    cout << n << "C" << r << " = " << nfact/(rfact * nrfact);
}
int main(){
    int n,r;
    cout << "Value of n : ";
    cin >> n;
    cout << "Value of r : ";
    cin >> r;

    ncr(n,r);
    cout << endl;
    return 0;
}