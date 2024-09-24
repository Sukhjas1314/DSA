#include<iostream>
using namespace std;
void spiral(int arr[3][3],int rows,int cols){
    int s_row = 0;
    int s_col = 0;
    int e_row = rows - 1;
    int e_col = cols - 1;

    while(s_row <= e_row && s_col <= e_col){
        for(int i = s_col ; i <= e_col ; i++){
            cout << arr[s_row][i] << " ";
        }
        s_row++;
        for(int j = s_row ; j <= e_row ; j++){
            cout << arr[j][e_col] << " ";
        }
        e_col--;
        if(s_row <= e_row){
            for(int i = e_col ; i >= s_col ; i--){
                cout << arr[e_row][i] << " ";
            }
            e_row--;
        }
        if(s_col <= e_col){
            for(int j = e_row ; j >= s_row ; j--){
                cout << arr[j][s_col] << " ";
            }
            s_col++;
        }
    }
}
int main(){
    int arr[3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}};
    cout << "The spiral matrix is : ";
    spiral(arr,3,3);

    cout << endl;
    return 0;
}