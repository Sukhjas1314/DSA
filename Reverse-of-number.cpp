#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n , a;
    cout << "Enter the number : ";
    cin >> n;
    a = n;

    int ans = 0;
    while(n != 0){
        int digit = n % 10;
        if((ans > INT_MAX / 10) || (ans < INT_MIN / 10)){
            cout << 0;
        }
        ans = ans * 10 + digit;
        n = n / 10;
    }
    cout << "The reverse of " << a << " is : " << ans ;
    cout << endl;
    return 0;
}