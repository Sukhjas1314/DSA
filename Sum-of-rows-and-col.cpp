#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout << "Enter the number of rows : ";
    cin >> a;
    cout << "Enter the number of columns : ";
    cin >> b;

    int mat[a][b];
    cout << "Enter the elements of the matrix : ";
    for(int i = 0 ; i < a ; i++){
        for(int j = 0 ; j < b ; j++){
            cin >> mat[i][j];
        }
    }
    cout << endl;

    for(int i = 0 ; i < a ; i++){
        int sumr = 0;
        for(int j = 0 ; j < b ; j++){
            sumr += mat[i][j];
        }
        cout << "The sum of row " << i + 1 << " : " << sumr << endl; 
    }
    for(int j = 0 ; j < b ; j++){
        int sumc = 0;
        for(int i = 0 ; i < a ; i++){
            sumc += mat[i][j];
        }
        cout << "The sum of column " << j + 1 << " : " << sumc << endl;
    }
    cout << endl;
    return 0;
}