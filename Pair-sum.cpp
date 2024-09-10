#include <iostream>
#include <vector>
#include <algorithm> // for min and max functions

using namespace std;

int main() {
    vector<int> arr1(6); // array to store 6 elements
    vector<vector<int> > ans; // 2D vector to store the pairs

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < arr1.size(); i++) {
        cin >> arr1[i];
    }
    cout << endl;

    int s;
    cout << "Enter the sum: ";
    cin >> s;

    // Finding pairs that sum up to 's'
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = i + 1; j < arr1.size(); j++) {
            if (arr1[i] + arr1[j] == s) {
                vector<int> temp;
                temp.push_back(min(arr1[i], arr1[j])); // store the smaller element first
                temp.push_back(max(arr1[i], arr1[j])); // store the larger element second
                ans.push_back(temp); // add the pair to the result vector
            }
        }
    }

    // Printing the resultant pairs
    cout << "The resultant pairs are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "(" << ans[i][0] << "," << ans[i][1] << ")" << endl;
    }

    return 0;
}
