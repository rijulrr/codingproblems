#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


vector<int> pairs(vector<int>& arr, int target) {

    unordered_set<int> seen;
    vector<int> res;

    for (int i = 0; i < arr.size(); i++) {
        
        int diff = target - arr[i];
        if ( seen.find(diff) == seen.end() ) {
            res.push_back(diff);
            res.push_back(arr[i]);
            return res;
        }

    }

    return {};

}


int main() {

    vector<int> arr = {2, 7, 11, 15};
    auto res = pairs(arr, 9);

    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

}