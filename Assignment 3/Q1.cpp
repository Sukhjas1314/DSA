#include<iostream>
#include<vector>
#include<string>
using namespace std;

string LCS(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int> > dp(n1 + 1,vector<int> (n2 + 1,0));

    for (int i = 1 ; i <= n1 ; i++){
        for (int j = 1 ; j <= n2 ; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
            }
        }
    }

    string lcs = "";
    int i = n1,j = n2;
    while(i > 0 && j > 0){
        if (s1[i - 1] == s2[j - 1]){
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    return lcs;
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    string lcs = LCS(s1,s2);
    cout << "Longest Common Subsequence : " << lcs << endl;

    return 0;
}