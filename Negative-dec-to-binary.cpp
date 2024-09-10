#include<iostream>
#include<math.h>
using namespace std;

int main(){
  long int n , a;
  cout << "Enter any decimal : ";
  cin >> n;
  a = n;

  unsigned long int i = 0 , ans = 0;
  if(n < 0){
    n = pow(2,16) + n;
  }
  while(n != 0){
    int bit = n & 1;
    ans = ans + (bit * pow(10 , i));
    n = n >> 1;
    i++;
  }
  cout << "Binary of " << a << " is : " << ans;
  cout << endl; 
  return 0;
}