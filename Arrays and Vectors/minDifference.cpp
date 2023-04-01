#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <iostream>

using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b) {

    if (a.empty() || b.empty()) {
        return {-1, -1};
    }

    int n = a.size();
    int m = b.size();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int diff = INT_MAX;
    int num1, num2;

    while (i < n && j < m) {
        int curDiff = abs(a[i] - b[j]);
        if (curDiff < diff) {
            diff = curDiff;
            num1 = a[i];
            num2 = b[j];
        }
        if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return {num1, num2};
}


int main() {
    vector<int> a = {23, 5, 10, 17, 30};
    vector<int> b = {26, 134, 135, 14, 19};

    auto ret = minDifference(a, b);

    cout << "The pair with min difference is: " << ret.first << ", " << ret.second << endl;

    return 0;
}
