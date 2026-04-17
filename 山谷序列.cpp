//
// Created by Ruizhe Hou on 2020/10/1.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param num: sequence
     * @return: The longest valley sequence
     */
    int valley(vector<int> &nums) {
        // write your code here
        int m = nums.size();

        vector<int> dp1(m, 1);
        dp1.insert(dp1.begin() + 1, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j]) dp1[i] = max(dp1[j] + 1, dp1[i]);
            }
        }
        //dp[i]是以nums[i]为开头的最长递增子序列长度
        vector<int> dp2(m, 1);
        for (int i = m - 2; i >= 0; i--) {
            for (int j = m - 1; j > i; j--) {
                if (nums[i] < nums[j]) dp2[i] = max(dp2[j] + 1, dp2[i]);
            }
        }

        int res = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                if (nums[i] == nums[j]) {
                    int temp = min(dp1[i], dp2[j]);
                    res = max(res, temp * 2);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1, 2, 2, 1, 3, 1};
    cout << sol.valley(nums) << endl;
    return 0;
}
