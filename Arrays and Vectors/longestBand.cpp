#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestBand(vector<int> arr) {
    
    int n = arr.size();

    // used for lookups - checking if we can form a sequence
    unordered_set<int> s;

    for (int i : arr) {
        s.insert(i);
    }

    int longest = 0;

    for (int element : arr) {
        int parent = element - 1;

        // forming a new chain since parent was not found
        if (s.find(parent) == s.end()) {

            int next_num = element + 1;
            int cnt = 1;

            // while the next parent exists
            while (s.find(next_num) != s.end()) {
                next_num++;
                cnt++;
            }

            longest = max(longest, cnt);

        }

    }
    return longest;

}


int main() {

    vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    auto res = longestBand(arr);

    cout << res << endl;
    
}