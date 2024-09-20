#include<iostream>
using namespace std;
long long int sqrt(int n){
    long long int s = 0;
    long long int e = n;
    long long int ans = -1;

    while(s <= e){
        long long int mid = s + (e - s) / 2;
        long long int square = mid * mid;

        if(square == n){
            return mid;
        }
        else if(square < n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}
double sqrt2(int n,int precision,int sqrt){
    double factor = 1;
    double ans = sqrt;
    for(int i = 0 ; i < precision ; i++){
        factor = factor / 10;
        for(double j = ans ; j*j < n ; j = j + factor){
            ans = j;
        }
    }
    return ans;
}
int main(){
    int x;
    cout << "Enter the number : ";
    cin >> x;

    int sqroot = sqrt(x);
    cout << "The square root of " << x << " is : " << sqroot << endl;
    double sqroot2 = sqrt2(x,3,sqroot);
    cout << "The precised square root of " << x << " is : " << sqroot2 << endl;
    return 0;
}