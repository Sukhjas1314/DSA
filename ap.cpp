#include<iostream>
using namespace std;
void nthterm(int n){
    int ap = 3 * n + 7;
    cout << "The last term is : " << ap << endl;
}
int main(){
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    nthterm(n);
    
    cout << endl;
    return 0;
}
