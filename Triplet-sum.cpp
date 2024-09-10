#include <iostream>
#include <vector>
// #include <algorithm> // for min and max functions

using namespace std;

int main() {
    vector<int> arr1(6); // array to store 6 elements
    vector<vector<int> > ans; // 2D vector to store the triplets

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < arr1.size(); i++) {
        cin >> arr1[i];
    }
    cout << endl;

    int s;
    cout << "Enter the sum: ";
    cin >> s;

    // Finding triplets that sum up to 's'
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = i + 1; j < arr1.size(); j++) {
            for (int k = j + 1; k < arr1.size(); k++) {
                if (arr1[i] + arr1[j] + arr1[k] == s) {
                    vector<int> temp;
                    temp.push_back(arr1[i]);
                    temp.push_back(arr1[j]);
                    temp.push_back(arr1[k]);
                    sort(temp.begin(), temp.end()); // sort the triplet
                    ans.push_back(temp); // add the sorted triplet to the result
                }
            }
        }
    }

    // Printing the resultant triplets
    if (ans.empty()) {
        cout << "No triplets found with the given sum." << endl;
    } else {
        cout << "The resultant triplets are: " << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i][0] << ", " << ans[i][1] << ", " << ans[i][2] << ")" << endl;
        }
    }

    return 0;
}
