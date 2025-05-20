#include<iostream>
#include<vector>
using namespace std;

bool place(int row,int col,vector<int>& queens){
    for(int i = 0 ; i < row ; i++){
        int placedCol = queens[i];
        if (placedCol == col || abs(placedCol - col) == abs(i - row)){
            return false;
        }
    }
    return true;
}

bool nQueens(int row,int n,vector<int>& queens){
    if (row == n){
        return true;
    }
    for (int col = 0 ; col < n ; col++){
        if (place(row,col,queens)){
            queens[row] = col;
            if (nQueens(row + 1,n,queens)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cout << "Enter the number of queens : ";
    cin >> n;

    vector<int> queens(n,-1);

    if (nQueens(0,n,queens)){
        cout << "One solution : [";
        for (int i = 0 ; i < n ; i++){
            cout << (queens[i] + 1);
            if (i != n - 1){
                cout << ", "; 
            } 
        }
        cout << "]" << endl;
    }
    else{
        cout << "No solution exists for n : " << n << endl;
    }

    return 0;
}