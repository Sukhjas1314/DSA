#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout << "Enter the rows of matrix 1 : ";
    cin >> a;
    cout << "Enter the columns of matrix 1 : ";
    cin >> b;

    int mat1[a][b] , transpose[b][a];

    cout << "Enter the elements of the matrix 1 : " << endl;
    for(int i = 0 ; i < a ; i++){
        for(int j = 0 ; j < b ; j++){
            cin >> mat1[i][j];
        }
    }
    for(int i = 0 ; i < b ; i++){
        for(int j = 0 ; j < a ; j++){
            transpose[i][j] = mat1[j][i];
        }
    }
    cout << endl;
    
    cout << "The transpose of matrix 1 : " << endl;
    for(int i = 0 ; i < b ; i++){
        for(int j = 0 ; j < a ; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}