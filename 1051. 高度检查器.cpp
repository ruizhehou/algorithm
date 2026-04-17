//
// Created by Ruizhe Hou on 2020/10/12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        int size = heights.size();
        vector<int> vec(heights);
        sort(vec.begin(), vec.end());
        int i = 0;
        int j = 0;
        int count = 0;
        for (i = 0, j = 0; j < size; i++, j++) {
            if (heights[i] != vec[j]) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> h1 = {1, 1, 4, 2, 1, 3};
    cout << sol.heightChecker(h1) << endl; // 3
    vector<int> h2 = {5, 1, 2, 3, 4};
    cout << sol.heightChecker(h2) << endl; // 5
    return 0;
}
