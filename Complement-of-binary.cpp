#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n , m;
    cout << "Enter a decimal number : ";
    cin >> n;
    m = n;

    int mask = 0;
    if(n == 0){
        cout << 1;
    }
    while(m != 0){
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~n) & mask;
    cout << "The complement of " << n <<  " is : " << ans << endl;
    return 0;
}