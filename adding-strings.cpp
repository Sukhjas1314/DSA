#include<iostream>
using namespace std;
string addStrings(string &num1,string &num2){
    int carry = 0;
    string result = "";
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while(i >= 0 || j >= 0 || carry > 0){
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        result = to_string(sum) + result; 
        i--;
        j--;
    }
    return result;
}
int main(){
    string str1,str2;
    cout << "Enter the 1st string : ";
    cin >> str1;
    cout << "Enter the 2nd string : ";
    cin >> str2;

    string result1 = addStrings(str1,str2);
    cout << "The resultant string is : " << result1 << endl;
    return 0;
}