#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minSwaps(vector<int> arr) {

    vector<int> sortedVec = arr;

    sort(sortedVec.begin(), sortedVec.end());

    int l = 0;
    int r = arr.size() - 1;

    



}


int main() {

    vector<int> arr = {10, 11, 5, 4, 3, 2, 1};
    auto ret = minSwaps(arr);

    cout << ret << endl;


}