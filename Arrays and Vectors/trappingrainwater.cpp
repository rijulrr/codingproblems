#include <iostream>
#include <vector>

using namespace std;


int trappingRainWater(vector<int> heights) {

    int l = 0, r = heights.size() - 1;

    int leftmax = heights[l], rightmax = heights[r];

    int res = 0;

    while (l < r) {
        if (leftmax < rightmax) {
            l += 1;
            leftmax = max(heights[l], leftmax);
            res += leftmax - heights[l];
        } else {
            r -= 1;
            rightmax = max(heights[r], rightmax);
            res += rightmax - heights[r];
        }
    } 

    return res;



}

int main() {

    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    auto ret = trappingRainWater(heights);

    cout << ret << endl;


}