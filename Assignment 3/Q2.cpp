#include<iostream>
#include<climits>
#include<string>
using namespace std;

void printOptimalParens(int i,int j,int split[10][10],string& result){
    if (i == j){
        result += 'M' + to_string(i);
        return;
    }
    result += "(";
    printOptimalParens(i,split[i][j],split,result);
    result += " x ";
    printOptimalParens(split[i][j] + 1,j,split,result);
    result += ")";
}

int main(){
    // int arr[] = {2,1,3,4};
    int arr[] = {5,4,6,2,7};
    int n = sizeof(arr)/sizeof(int);

    int dp[10][10] = {0};
    int split[10][10] = {0};

    for (int len = 2 ; len < n ; len++){
        for(int i = 1 ; i < n - len + 1 ; i++){
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i ; k < j ; k++){
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j]){
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    string result = "";
    printOptimalParens(1,n - 1,split,result);

    cout << "Efficient way : " << result << endl;
    cout << "Multiplication output : " << dp[1][n - 1] << endl;

    return 0;
}