#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cout << "Enter the rows of matrix 1 : ";
    cin >> a;
    cout << "Enter the columns of matrix 1 : ";
    cin >> b;
    cout << "Enter the rows of matrix 2 : ";
    cin >> c;
    cout << "Enter the columns of matrix 2 : ";
    cin >> d;

    int mat1[a][b] , mat2[c][d] , res[a][d];

    cout << "Enter the elements of the matrix 1 : " << endl;
    for(int i = 0 ; i < a ; i++){
        for(int j = 0 ; j < b ; j++){
            cin >> mat1[i][j];
        }
    }
    cout << endl;

    cout << "Enter the elements of the matrix 2 : " << endl;
    for(int i = 0 ; i < c ; i++){
        for(int j = 0 ; j < d ; j++){
            cin >> mat2[i][j];
        }
    }
    cout << endl;

    if(b != c){
        cout << "Multiplication is not possible.";
    }
    else{
        for(int i = 0 ; i < b ; i++){
            for(int j = 0 ; j < c ; j++){
                res[i][j] = 0;
            }
        }
        for(int i = 0 ; i < a ; i++){
            for(int j = 0 ; j < d ; j++){
                for(int k = 0 ; k < b ; k++){
                    res[i][j] += mat1[i][k] * mat2[k][j]; 
                }
            }
        }
        cout << "The resultant matrix : " << endl;
        for(int i = 0 ; i < a ; i++){
            for(int j = 0 ; j < d ; j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}