//
// Created by Ruizhe Hou on 2020/10/11.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        int target = sum >> 1;
        bool dp[target + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
            if (dp[target]) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {1, 5, 11, 5};
    cout << sol.canPartition(n1) << endl; // 1
    vector<int> n2 = {1, 2, 3, 5};
    cout << sol.canPartition(n2) << endl; // 0
    return 0;
}