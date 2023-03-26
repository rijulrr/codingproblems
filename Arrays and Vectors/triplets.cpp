#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> triplets(vector<int> arr, int target) {

    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;

    for (int i = 0; i < n - 3; i++) {

        int j = i + 1;
        int k = n - 1;
        
        while (j < k) {
            int combination_sum = arr[i];
            combination_sum += arr[j];
            combination_sum += arr[k];

            if (combination_sum == target) {
                res.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            } else if (combination_sum > target) {
                k--;
            } else {
                j++;
            }

        }

    }

    return res;

}


int main() {

    vector<int> arr = {15, 2, 1, 4, 5, 6, 7, 8, 3, 9};
    auto res = triplets(arr, 18);

    for (auto x : res) {
        for (auto y : x) 
            cout << y << " ";
        cout << endl;
    }
}