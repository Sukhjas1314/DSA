#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N = 4;
    int W = 7;
    int profit[] = {5,3,8,6};
    int weight[] = {2,3,4,5};

    int dp[5][8] = {0};

    for (int i = 1 ; i <= N ; i++){
        for (int w = 1 ; w <= W ; w++){
            if (weight[i - 1] <= w){
                dp[i][w] = max(dp[i - 1][w],profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<int> selectedItems;
    int w = W;
    for (int i = N ; i > 0 && w > 0 ; i--){
        if (dp[i][w] != dp[i - 1][w]){
            selectedItems.push_back(i);
            w -= weight[i - 1];
        }
    }

    cout << "Items selected are : " << endl;
    for (int i = selectedItems.size() - 1 ; i >= 0 ; i--){
        cout << "Item : " << selectedItems[i];
        if (i > 0) cout << " and ";
    }
    cout << endl;
    cout << "Maximum profit : " << dp[N][W] << endl;

    return 0;
}