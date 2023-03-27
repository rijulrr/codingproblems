#include <iostream>
#include <vector>

using namespace std;

int mountain(vector<int> arr) {
    
    int n = arr.size();

    int largest = 0;

    for (int i = 1; i <= n - 2;) {

        // peak
        if ( arr[i] > arr[i-1] and arr[i] > arr[i+1] ) {

            int cnt = 1;
            int j = i;

            // count backwards
            while ( j>=1 and arr[j] > arr[j-1] ) {
                j--;
                cnt++;
            }

            // count forwards
            while ( i<=n-2 and arr[i] > arr[i+1] ) {
                i++;
                cnt++;
            }

            largest = max( largest, cnt );

        } else {
            i++;
        }



    }

    return largest;



}


int main() {

    vector<int> arr = {0, 1, 0};
    auto res = mountain(arr);

    cout << res << endl;

    return 0;
    
}