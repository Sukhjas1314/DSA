#include<iostream>
using namespace std;
bool checkPalindrome(char str[],int n){
    int s = 0;
    int e = n - 1;
    for(int i = 0 ; i < n ; i++){
        str[i] = tolower(str[i]);
    }
    while(s <= e){
        while(s < e && !isalnum(str[s])){
            s++;
        }
        while(s < e && !isalnum(str[e])){
            e--;
        }
        if(str[s] != str[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
char getMaxOccurence(string s){
    int arr[26] = {0};
    for(int i = 0 ; i < s.size() ; i++){
        char ch = s[i];
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }
    int maxi = -1 , ans = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    return ans + 'a';
}
void reverse(string name){
    for(int i = name.size() - 1 ; i >= 0 ; i--){
        cout << name[i];
    }
    cout << endl;
}
int length(char name[]){
    int count = 0;
    for(int i = 0 ; name[i] != '\0' ; i++){
        count++;
    }
    return count;
}
int main(){
    char name[50];
    cout << "Enter your name : ";
    cin >> name;

    cout << "Hello " << name << endl;
    cout << length(name) << endl;

    cout << "Reverse of your name : " ;
    reverse(name);
    cout << endl;

    cout << "Palindrome or not : " << checkPalindrome(name,length(name));
    cout << endl;

    cout << "Maximum occurence is of : " << getMaxOccurence(name) << endl;
    cout << endl;
    return 0;
}