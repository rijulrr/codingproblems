#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxSubarraySum(vector<int> arr) {
    
    //Complete this function, your function should return the maximum subarray sum
    // -1,2,3,4,-2,6,-8,3
    // ans: 13
    
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        arr[i] = max(arr[i], arr[i] + arr[i-1]);
    }
    
    int max = *max_element(arr.begin(), arr.end());
    
    if (max == -1)
        return 0;
    
    return max;
    
    
}

int main() {

    vector<int> arr = {-1,2,3,4,-2,6,-8,3};
    auto ret = maxSubarraySum(arr);

    cout << ret << endl;


}