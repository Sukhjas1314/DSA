#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int mat[6][5] = {
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}
    };

    int dp[6][5] = {0};
    int maxsize = 0;

    for (int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if (i == 0 || j == 0){
                dp[i][j] = mat[i][j];
            }
            else if (mat[i][j] == 1){
                dp[i][j] = 1 + min(dp[i - 1][j],min(dp[i][j - 1],dp[i - 1][j - 1]));
            }
            else{
                dp[i][j] = 0;
            }
            maxsize = max(maxsize,dp[i][j]);
        }
    }
    
    cout << "Maximal Square possible is of side : " << maxsize << endl;
    return 0;
}