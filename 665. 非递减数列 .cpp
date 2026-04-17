//
// Created by houruizhe on 2021/2/7.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
                if (i > 0 && y < nums[i - 1]) {
                    nums[i + 1] = x;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {4, 2, 3};
    cout << sol.checkPossibility(n1) << endl; // 1
    vector<int> n2 = {4, 2, 1};
    cout << sol.checkPossibility(n2) << endl; // 0
    return 0;
}