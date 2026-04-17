//
// Created by Ruizhe Hou on 2020/10/9.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int m1 = 1, m2 = 1, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > m1) {
                m2 = m1;
                m1 = nums[i];
            } else if (nums[i] > m2) {
                m2 = nums[i];
            }
        }
        return (m1 - 1) * (m2 - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 4, 5, 2};
    cout << sol.maxProduct(nums1) << endl; // 12
    vector<int> nums2 = {1, 5, 4, 5};
    cout << sol.maxProduct(nums2) << endl; // 16
    return 0;
}