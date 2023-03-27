#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool outOfOrder(vector<int> arr, int j) {
    int x = arr[j];
    if (j == 0) {
        return x > arr[1];
    }
    else if (j == arr.size() - 1) {
        return x < arr[j-1];
    }
    return x > arr[j+1] or x < arr[j-1];

}

pair<int, int> subarraySort(vector<int> arr) {

    int n = arr.size();
    int smallest = std::numeric_limits<int>::max();
    int largest = std::numeric_limits<int>::min();

    for (int i = 0; i < n; i++) {
        
        int x = arr[i];

        if (outOfOrder(arr, i)) {

            smallest = min(smallest, x);
            largest = max(largest, x);
        }

    }

    if (smallest == std::numeric_limits<int>::max()) {
        return {-1, -1};
    }

    int left = 0;
    while (smallest >= arr[left]) {
        left++;
    }
    
    int right = n - 1;
    while (largest <= arr[right]) {
        right--;
    }


    return {left, right}; 

}




int main() {


    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto res = subarraySort(arr);

    cout << res.first << " and " << res.second << endl;

    return 0;
}